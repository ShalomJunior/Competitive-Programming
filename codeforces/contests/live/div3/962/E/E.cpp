#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    s = "#" + s;
    map<int, vector<int>> h;
    h[0].push_back(0);
    int pref = 0;
    for (int i = 1; i <= n; i++) {
        pref += s[i] == '0' ? -1 : 1;
        h[pref].push_back(i);
    }
    int ans = 0;
    for (auto& [k, v] : h) {
        int m = v.size();
        int l = v[0] + 1;
        for (int i = 1; i < m; i++) {
            ans += l * (n - v[i] + 1) % MOD;
            ans %= MOD;
            l += v[i] + 1;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
