#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] = max(dp[i][j], 1LL);
        }
    }
    cout << dp[n][m] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}