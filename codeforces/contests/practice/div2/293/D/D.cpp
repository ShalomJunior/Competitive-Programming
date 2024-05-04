#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, t;
    double p;
    cin >> n >> p >> t;
    vector<vector<double>> dp(t + 1, vector<double>(n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j <= n; j++) {
            if (j == 0) {
                dp[i][j] = (1 - p) * dp[i - 1][j];
            }
            else {
                dp[i][j] = (1 - p) * dp[i - 1][j] + p * dp[i - 1][j - 1];
            }
        }
    }
    for (int i = 0; i < t + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    double ans = 0;
    for (int j = 0; j <= n; j++) {
        cout << dp[t][j] << " ";
        ans += dp[t][j] * j;
    }
    cout << endl;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
