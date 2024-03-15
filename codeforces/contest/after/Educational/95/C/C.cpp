#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int dp[n][4];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = a[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][2], dp[i - 1][3]) + a[i];
        dp[i][1] = dp[i - 1][0] + a[i];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        dp[i][3] = dp[i - 1][2];
    }
    int ans = INF;
    for (auto& c : dp[n - 1]) ans = min(ans, c);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}