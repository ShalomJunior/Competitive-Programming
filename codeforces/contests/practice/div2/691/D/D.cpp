#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    int A = accumulate(a.begin(), a.end(), 0);
    int B = accumulate(b.begin(), b.end(), 0);
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(A + 1, -INF)));
    dp[0][0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int s = 0; s <= A; s++) {
                if (i > 0) {
                    dp[i][j][s] = dp[i - 1][j][s];
                }
                if (s >= a[i] && j > 0) {
                    dp[i][j][s] = max(dp[i][j][s], dp[i - 1][j - 1][s - a[i]] + b[i]);
                }
            }
        }
    }
    vector<double> ans(n + 1);
    for (int j = 1; j <= n; j++) {
        for (int s = 1; s <= A; s++) {
            double m = dp[n][j][s];
            ans[j] = max(ans[j], min((double)s, (m + B) / 2));
        }
        cout << fixed << setprecision(16) << ans[j] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
