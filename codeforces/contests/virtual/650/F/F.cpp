#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n = 20, m = 20;
    int dp[n][m];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i) dp[i][j] += dp[i - 1][j];
            if (j) dp[i][j] += dp[i][j - 1];
        }
    }
    cout << dp[n - 1][m - 1] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}