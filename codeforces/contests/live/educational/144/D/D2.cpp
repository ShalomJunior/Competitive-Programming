#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int dp[n + 1][k + 1][3];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (i < j) {
                for (int e : {0, 1, 2}) dp[i][j][e] = -INF;
                continue;
            }
            dp[i][j][0] = max(dp[i - 1][j][0], 0LL) + a[i] - x;
            if (j > 0)
                dp[i][j][1] = max({ dp[i - 1][j - 1][0], dp[i - 1][j - 1][1], 0LL }) + a[i] + x;
            else
                dp[i][j][1] = -INF;
            dp[i][j][2] = max(dp[i - 1][j][1], dp[i - 1][j][2]) + a[i] - x;
        }
        for (int e : {0, 1, 2}) ans = max(ans, dp[i][k][e]);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}