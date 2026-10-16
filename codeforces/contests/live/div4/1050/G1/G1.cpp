#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    map<int, int> h;
    for (int i = 0; i < k - 1; i++) h[a[i]]++;
    multiset<int> ms;
    for (auto& [k, v] : h) ms.insert(v);
    vector<int> cnt(n);
    for (int i = 0; i + k - 1 < n; i++) {
        int j = i + k - 1;
        auto it = ms.find(h[a[j]]);
        if (it != ms.end()) ms.erase(it);
        ms.insert(++h[a[j]]);
        cnt[i] = *prev(ms.end());
        it = ms.find(h[a[i]]);
        if (it != ms.end()) ms.erase(it);
        ms.insert(--h[a[i]]);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        cout << r - l + 1 - cnt[l] << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
