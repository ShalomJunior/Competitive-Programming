#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(k + 1));
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(a.begin(), a.end(), a[i] - 5);
        int idx = it - a.begin();
        for (int j = 0; j < k; j++) {
            dp[i][j + 1] = max(i ? dp[i - 1][j + 1] : 0, i - idx + 1 + (idx ? dp[idx - 1][j] : 0));
            ans = max(ans, dp[i][j + 1]);
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}