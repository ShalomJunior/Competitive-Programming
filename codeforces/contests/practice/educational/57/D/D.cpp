#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 4;
const int INF = 1e18;
const string S = "#hard";
void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    s = "#" + s;
    vector<vector<int>> dp(n + 1, vector<int>(N, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < N; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + (s[i] == S[j + 1] ? a[i] : 0);
            }
            else {
                if (s[i] == S[j]) {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]);
                }
                else {
                    dp[i][j] = dp[i - 1][j] + (s[i] == S[j + 1] ? a[i] : 0);
                }
            }
        }
    }
    cout << *min_element(dp[n].begin(), dp[n].end()) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
