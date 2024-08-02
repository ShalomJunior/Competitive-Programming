#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 5);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> dp(n + 5, vector<int>(k + 5, INF));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (i == 0) {
                dp[i][j] = (j == 0 ? 0 : INF);
                continue;
            }
            int mn = a[i];
            for (int u = 0; 0 < i - u && 0 <= j - u; u++) {
                mn = min(mn, a[i - u]);
                dp[i][j] = min(dp[i][j], mn * (u + 1) + dp[i - u - 1][j - u]);
            }
        }
    }
    int ans = INF;
    for (int j = 0; j <= k; j++) ans = min(ans, dp[n][j]);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}