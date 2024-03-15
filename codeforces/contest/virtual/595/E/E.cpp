#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, c; cin >> n >> c;
    vector<int> a(n - 1), b(n - 1);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    int dp[n][2];
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a[i - 1];
        dp[i][1] = min(dp[i - 1][0] + c, dp[i - 1][1] + (i == 1 ? c : 0)) + b[i - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << min(dp[i][0], dp[i][1]) << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}