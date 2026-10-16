#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.length();
    if (s > t) {
        cout << -1;
    }
    else if (s == t) {
        cout << 0;
    }
    else {
        int j = 0;
        while (j < n && s[j] == '0') j++;
        int cnt = count(s.begin(), s.end(), '0');
        if (cnt == n) {
            cout << n;
        }
        else if (cnt == n - 1) {
            cout << j;
        }
        else {
            int ans = j;
            for (int k = n - 1, m = 1; k >= j; k--) {
                if (s[k] == '0') {
                    ans = (ans + m) % MOD;
                }
                m = m * 2 % MOD;
            }
            cout << ans;
        }
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
