#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for (auto& c : a) {
        cin >> c;
        cnt[c]++;
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    int m = a.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++) {
        int v = cnt[a[i - 1]];
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            if (v <= i && j >= v) {
                dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - v]);
            }
        }
    }
    int ans = m;
    for (int i = 1; i <= m && i * 2 <= n; i++) {
        if (dp[m][i] >= m - i) {
            assert(dp[m][i] <= i);
            ans = min(ans, i);
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
