#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(3));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0], 0LL) + a[i];
        dp[i][1] = max({ dp[i - 1][0], dp[i - 1][1], 0LL }) + x * a[i];
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
        for (int j : {0, 1, 2}) ans = max(ans, dp[i][j]);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}