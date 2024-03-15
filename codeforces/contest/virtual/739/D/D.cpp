#include <bits/stdc++.h>
#define int long long
using namespace std;

auto LCS(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> lcs(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                lcs[i][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }
    return lcs;
}

void solve() {
    string s; cin >> s;
    int n = s.size();
    int ans = n + 1;
    for (int i = 0; i < 61; i++) {
        string match = to_string(1LL << i);
        int m = match.length();
        auto lcs = LCS(s, match);
        for (int j = 1; j <= m; j++) {
            int len = lcs[n][j];
            if (len == j) {
                int cost = n - j + m - j;
                ans = min(ans, cost);
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}