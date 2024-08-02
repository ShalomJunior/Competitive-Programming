#include <bits/stdc++.h>
#define int long long
using namespace std;

const int H = 1e5;
const int INF = 1e12;
void solve() {
    int m, x;
    cin >> m >> x;
    vector<int> c(m + 2);
    vector<int> h(m + 2);
    for (int i = 1; i <= m; i++) cin >> c[i] >> h[i];
    vector<vector<int>> dp(m + 5, vector<int>(H + 5, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= m + 1; i++) {
        dp[i][0] = 0;
        for (int j = 1; j <= H; j++) {
            dp[i][j] = dp[i - 1][j];
            int mn = 0;
            for (int k = i; k > 0; k--, mn += x) {
                // if (i == 2 && j == 1) {
                //     cerr << "h[i] " << endl;
                // }
                if (mn >= c[i - 1] && h[i] <= j) {
                    //cerr << "mn  = " << mn << endl;
                    // if (j < 5) {
                    //     cerr << i << " {} " << j << endl;
                    //     cerr << "| " << j - h[i] << endl;
                    //     cerr << dp[k - 1][j - h[i]] << endl;
                    // }
                    dp[i][j] = min(dp[i][j], c[i - 1] + dp[k - 1][j - h[i]]);
                }
            }

            // if (k == 1 && j == 10) {
            //     cerr << "dp[i][j] = " << dp[i][j] << endl;
            // }
        }
    }
    for (int i = 1; i <= m + 1; i++) {
        for (int j = 0; j < 10; j++) {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }
    int ans = 0;
    for (int i = 0; i <= H; i++) {
        if (dp[m][i] != INF) {
            ans = max(ans, i);
        }
    }
    cout << ans << endl;
    cerr << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
