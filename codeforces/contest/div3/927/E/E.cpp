#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i] + s[i] - '0';
    }
    vector<int> ans(n + 1);
    for (int i = n; i >= 0; i--) {
        ans[i] = dp[i] % 10;
        if (i)dp[i - 1] += dp[i] / 10;
    }
    string res;
    for (auto& c : ans) res += to_string(c);
    int i = 0;
    int m = res.size();
    while (i < m && res[i] == '0')i++;
    cout << (i == m ? 0 : res.substr(i, m - i)) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
