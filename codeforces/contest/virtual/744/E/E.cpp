#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.rbegin(), a.rend());
    vector<int> pref(n);
    for (int i = 0; i < n; i++) {
        pref[i] = a[i] + ((i) ? pref[i - 1] : 0);
    }
    while (q--) {
        int k; cin >> k;
        auto it = lower_bound(pref.begin(), pref.end(), k);
        if (it == pref.end()) { cout << -1 << endl; continue; }
        int ans = it - pref.begin() + 1;
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}