#include <bits/stdc++.h>
using namespace std;

const int INF = 5000;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<vector<int>> dp(n, vector<int>(2, INF));
    dp[0][0] = a[0];
    dp[0][1] = a[0] / 10 <= a[0] % 10 ? a[0] % 10 : a[0];
    for (int i = 1; i < n; i++) {
        int last = min(dp[i - 1][0], dp[i - 1][1]);
        if (a[i] >= last)
            dp[i][0] = a[i];

        if (a[i] < 10 && a[i] >= last)
            dp[i][1] = a[i];

        if (a[i] >= 10) {
            if (a[i] / 10 <= a[i] % 10 && last <= a[i] / 10) {
                dp[i][1] = min(dp[i][1], a[i] % 10);
            }
        }
        if (dp[i][0] == INF && dp[i][1] == INF) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
