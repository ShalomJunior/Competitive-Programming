#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;
    s = "L" + s + "L";
    vector<int> dp(n + 2, k + 1);
    dp[0] = 0;
    for (int i = 0; i <= n + 1; i++) {
        if (s[i] == 'C') {
            dp[i] = k + 1;
        }
        else if (s[i] == 'W') {
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        }
        else {
            for (int j = 1; j <= m && i + j <= n + 1; j++) {
                dp[i + j] = min(dp[i + j], dp[i]);
            }
        }
    }
    cout << (dp[n + 1] <= k ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}