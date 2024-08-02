#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 501;
void solve() {
    int n, m, b, MOD;
    cin >> n >> m >> b >> MOD;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> dp(m + 1, vector<int>(b + 1));
    dp[0][0] = 1;
    for (int line = 1; line <= m; line++) {
        for (int mis = 0; mis <= b; mis++) {
            for (int dev = 1; dev <= n; dev++) {
                if (mis - a[dev] >= 0) {
                    dp[line][mis] += dp[line - 1][mis - a[dev]];
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= b; j++) {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }
    cerr << endl;
    int ans = 0;
    for (int mis = 0; mis <= b; mis++) ans += dp[m][mis];
    cout << ans % MOD << endl;
    assert(ans % n == 0);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)
        solve();
}
