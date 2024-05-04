#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), pref(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i] = a[i] + (i ? pref[i - 1] : 0);
    }
    while (m--) {
        int x; cin >> x;
        auto it = lower_bound(pref.begin(), pref.end(), x);
        int id = it - pref.begin();
        int num = x - (id ? pref[id - 1] : 0);
        cout << id + 1 << " " << num << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}