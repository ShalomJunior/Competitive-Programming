#include <bits/stdc++.h>
using namespace std;

const int N = 2;
const int INF = 1e9;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<vector<int>> dp(n, vector<int>(N));
    vector<int> b(n);
    dp[0][0] = INF;
    dp[0][1] = (a[0] > 0 ? 1 : 0);
    b[0] = min(dp[0][0], dp[0][1]);
    for (int i = 1; i < n; i++) {
        if (a[i] > 0) {
            dp[i][0] = (max(a[i - 1], a[i]) + 1) / 2 + (i - 2 >= 0 ? b[i - 2] : 0);
            dp[i][1] = 1 + b[i - 1];
        }
        else {
            dp[i] = dp[i - 1];
        }
        b[i] = min(dp[i][0], dp[i][1]);
    }
    for (auto& c : b) cerr << c << " -> ";
    cerr << endl;
    cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
    cerr << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
