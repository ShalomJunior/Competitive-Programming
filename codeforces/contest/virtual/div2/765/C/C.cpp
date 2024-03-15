#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 501;
int dp[N][N][N];
void solve() {
    int n, l, k; cin >> n >> l >> k;
    vector<int> x(n), s(n);
    for (auto& c : x) cin >> c;
    for (auto& c : s) cin >> c;
    x.push_back(l);
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            for (int u = 0; u <= k; u++) {
                if (i - j - 1 > u || j < u - (i - j - 1)) {
                    dp[i][j][u] = INF;
                }
                else {
                    dp[i][j][u] = dp[j][N - 1][u - (i - j - 1)] + s[j] * (x[i] - x[j]);
                }
                if (dp[i][N - 1][u] == 0) dp[i][N - 1][u] = dp[i][j][u];
                else {
                    dp[i][N - 1][u] = min(dp[i][N - 1][u], dp[i][j][u]);
                }
            }
        }
    }
    cout << dp[n][N - 1][k] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}