#include <bits/stdc++.h>
using namespace std;

string S;
const int N = 2000;
bool is(string s) {
    int n = s.length();
    if (n == 1) return false;
    return s == S.substr(0, n) || s == S.substr(1, n);
}

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    s = "#" + s;
    vector<int> dp(n + 1, n);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        string t;
        for (int j = 1; j <= k && i - j + 1 >= 1; j++) {
            t += s[i - j + 1];
            if (!is(t)) {
                dp[i] = min(dp[i], (i - j + 1 > 1 ? 1 : 0) + dp[i - j]);
            }
        }
    }
    cout << dp[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (S.size() < N) S += "01";
    int t; cin >> t;
    while (t--)solve();
}