#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5;
const int INF = 5e18;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    vector<vector<int>> dp(n, vector<int>(N, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (i == 0) {
                    dp[i][j] = j * b[i];
                }
                else {
                    if (a[i - 1] + k != a[i] + j) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + j * b[i]);
                    }
                }
            }
        }
    }
    cout << *min_element(dp[n - 1].begin(), dp[n - 1].end()) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
