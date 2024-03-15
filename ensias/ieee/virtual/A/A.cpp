#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (1LL * res * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return pow(x, MOD - 2);
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> dp(k, vector<int>(k, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n + m - 1; i += k - 1) {
        int x = min(k - 1, n - ((k - 1) * i / (k - 1)));
        int y = min(k - 1, m - ((k - 1) * i / (k - 1)));
        vector<vector<int>> ndp(k, vector<int>(k, 0));
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < k; l++) {
                if (dp[j][l] == 0) continue;
                for (int p = 0; p <= x && p <= j; p++) {
                    for (int q = 0; q <= y && q <= l; q++) {
                        if (p + q == 0 || p + q == k) continue;
                        int nj = j - p + q;
                        int nl = l - q + p;
                        ndp[nj][nl] = (ndp[nj][nl] + dp[j][l]) % MOD;
                    }
                }
            }
        }
        dp = ndp;
    }

    int ans = 0;
    for (int j = 0; j < k; j++) {
        for (int l = 0; l < k; l++) {
            if (dp[j][l] == 0) continue;
            int num = m + j;
            int den = n + m + j + l;
            ans = (ans + (1LL * dp[j][l] * inv(pow(den, MOD - 2))) % MOD * num) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}
