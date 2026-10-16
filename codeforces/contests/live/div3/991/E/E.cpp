#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    a = "#" + a;
    b = "#" + b;
    c = "#" + c;
    int n = a.length();
    int m = b.length();
    auto check = [&](char c1, char c2) {
        return c1 == c2 ? 0 : 1;
        };
    vector<vector<int>> dp(n, vector<int>(m, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = min({ dp[i][j],
            i ? check(a[i], c[i + j]) + dp[i - 1][j] : INF,
            j ? check(b[j], c[i + j]) + dp[i][j - 1] : INF });
        }
    }
    cout << dp[n - 1][m - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
