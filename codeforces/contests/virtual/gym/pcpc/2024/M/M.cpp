#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
void solve() {
    string l, r, s;
    cin >> l >> r >> s;
    int n = s.length();
    vector<int> pref(n);
    for (int i = 0; i + 1 < n; i++) {
        pref[i + 1] = pref[i] + (s[i] == '>' ? 1 : -1);
    }
    multiset<int> ms(pref.begin() + 1, pref.end());
    vector<int> x(n, 0);
    vector<int> y(n, 9);
    for (int i = 0; i < n; i++) {
        ms.erase(ms.find(pref[i]));
        if (*prev(ms.end()) >= pref[i]) {
            y[i] = 9 - (*prev(ms.end()) - pref[i]);
        }
        if (*ms.begin() <= pref[i]) {
            x[i] = (*ms.begin() - pref[i]);
        }
        int L = l[i];
        int R = r[i];
    }
    int ans = 1;
    vector<int> suff(n);
    for (int i = n - 1; i > 0; i--) {

    }
    for (int i = 0; i <= n; i++) {
        if (x[i] < 0 || y[i] > 9) {
            cout << 0 << endl;
            return;
        }
        ans = ans * (y[i] - x[i] + 1) % MOD;
    }
    cout << ans << endl;
}



/*
1 9
>
0 1
9
*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
