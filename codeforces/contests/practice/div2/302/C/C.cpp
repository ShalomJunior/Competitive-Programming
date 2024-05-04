#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 501;
int dp[N][N];
void solve() {
    int n, m, b, MOD;
    cin >> n >> m >> b >> MOD;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0] = 1;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            for (int k = 0; k <= b; k++) {
                if (k >= a[j]) {
                    dp[i][k] += dp[i - 1][k - a[j]];
                    dp[i][k] %= MOD;
                }
            }
        }
    }
    int ans = 0;
    for (int k = 0; k <= b; k++) {
        ans += dp[m][k];
        ans %= MOD;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
// int t; cin >> t;
// while (t--)
