#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int q; cin >> q;
    vector<int> s(26), t(26);
    int ls = ++s[0], lt = ++t[0];
    while (q--) {
        int d, k; string add;
        cin >> d >> k >> add; d--;
        (d) ? lt += (k * (int)add.size()) : ls += (k * (int)add.size());
        for (auto& c : add) {
            (d) ? t[c - 'a'] += k : s[c - 'a'] += k;
        }
        bool b = false;
        for (int i = 1; i < 26; i++) {
            if (t[i]) { b = true; break; }
        }
        cout << ((b || (s[0] == ls && ls < lt)) ? "YES" : "NO") << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}