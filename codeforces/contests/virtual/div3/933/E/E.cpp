#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
        multiset<int> f;
        f.insert(dp[i][0]);
        for (int j = 1; j < m; j++) {
            dp[i][j] = *f.begin() + a[i][j] + 1;
            f.insert(dp[i][j]);
            if (j - (d + 1) >= 0) {
                f.erase(f.find(dp[i][j - (d + 1)]));
            }
        }
    }
    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + dp[i][m - 1];
    int ans = INF;
    for (int i = k; i <= n; i++)ans = min(ans, pre[i] - pre[i - k]);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}