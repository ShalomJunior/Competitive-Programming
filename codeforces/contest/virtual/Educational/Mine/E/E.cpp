#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, V; cin >> n >> V;
    vector<int> v(n), s(n);
    for (auto& c : v) cin >> c;
    for (auto& c : s) cin >> c;
    vector<vector<int>> dp(V + 1, vector<int>(n));
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= v[j]) {
                dp[i][j] = s[j];
                dp[i][j] += (j - 1 >= 0 ? dp[i - v[j]][j - 1] : 0);
            }
            else dp[i][j] = (j - 1 >= 0 ? dp[i][j - 1] : 0);
            dp[i][j] = max(dp[i][j], (j - 1 >= 0 ? dp[i][j - 1] : 0));
        }
    }
    cout << dp[V][n - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
