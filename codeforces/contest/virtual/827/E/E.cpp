#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n), pref(n);
    for (int i = 0; i < n; i++) {
        int h; cin >> h;
        a[i] = max(h, (i) ? a[i - 1] : 0);
        pref[i] = h + ((i) ? pref[i - 1] : 0);
    }
    while (q--) {
        int h; cin >> h;
        auto i = upper_bound(a.begin(), a.end(), h) - a.begin();
        cout << ((i) ? pref[i - 1] : 0) << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}