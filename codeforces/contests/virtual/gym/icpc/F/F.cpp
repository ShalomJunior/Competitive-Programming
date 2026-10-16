#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

const int MOD = 1000000007;

// Main function
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e, k;
    cin >> n >> e >> k;

    // Build allowed[i][j]: soldier i (first row) can pair with soldier j (second row)
    // if |i-j| <= e. (We use 0-indexing.)
    vector<vector<bool>> allowed(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(i - j) <= e)
                allowed[i][j] = true;
        }
    }
    for (int a = 0; a < k; a++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // convert to 0-indexed
        // Only “forbid” if (u,v) was originally allowed (i.e. within the band).
        if (abs(u - v) <= e)
            allowed[u][v] = false;
    }

    // We use DP with a fixed window length L = 2*e + 1.
    int L = 2 * e + 1;
    // dp[i][mask] is the number of ways to process soldiers 0...i-1
    // and the current "window" for soldier i covers second row indices [i-e, i+e].
    // For positions j outside [0,n-1], we force the bit to 1.
    vector<vector<int>> dp(n + 1, vector<int>(1 << L, 0));

    // Function to determine the initial bit for a given window position p at state i.
    auto validBit = [&](int i, int p) -> int {
        int j = i - e + p;  // window covers j = i-e + p
        if (j < 0 || j >= n) return 1;  // out-of-bound: treated as "already used"
        return 0; // available
        };

    // Compute the initial mask for i = 0 (window covers indices [-e, e]).
    int init_mask = 0;
    for (int p = 0; p < L; p++) {
        int bit = validBit(0, p);
        if (bit == 1)
            init_mask |= (1 << p);
    }
    dp[0][init_mask] = 1;

    // Precompute new right–bit when shifting from state i to i+1.
    // After processing soldier i, the new window covers indices [ (i+1)-e, (i+1)+e ],
    // so the new rightmost bit corresponds to index (i+1)+e.
    vector<int> newRight(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        int j = (i + 1) + e;
        if (j < 0 || j >= n) newRight[i] = 1;
        else newRight[i] = 0;
    }

    // DP transitions
    for (int i = 0; i < n; i++) {
        // For each dp state at row i:
        for (int mask = 0; mask < (1 << L); mask++) {
            int ways = dp[i][mask];
            if (!ways) continue;
            // The current window covers j = i-e + p, for p=0,...,L-1.
            for (int p = 0; p < L; p++) {
                int j = i - e + p;
                if (j < 0 || j >= n) continue;       // out-of-bound positions
                if (mask & (1 << p)) continue;         // position already used
                if (!allowed[i][j]) continue;          // forbidden pairing
                // Use this pairing: mark bit p as used.
                int new_mask_current = mask | (1 << p);
                // Now shift the window:
                // The old window [i-e, i+e] becomes new window [ (i+1)-e, (i+1)+e ].
                // So drop the lowest bit and shift right.
                int shifted = new_mask_current >> 1;
                // Now set the new rightmost bit (position L-1) to newRight[i].
                int new_mask = (shifted & ((1 << (L - 1)) - 1)) | (newRight[i] << (L - 1));
                dp[i + 1][new_mask] = (dp[i + 1][new_mask] + ways) % MOD;
            }
        }
    }

    // Final state: i == n. The window covers indices [n-e, n+e].
    // For each window position p, the corresponding second row index is j = n - e + p.
    // For j that fall within [0,n) they must be paired (bit = 1); for j out-of-bound, they are forced to 1.
    int target = 0;
    for (int p = 0; p < L; p++) {
        int j = n - e + p;
        // In a valid final state all valid j must be occupied (bit 1).
        target |= (1 << p);
    }
    int ans = dp[n][target] % MOD;
    cout << ans << "\n";

    return 0;
}
