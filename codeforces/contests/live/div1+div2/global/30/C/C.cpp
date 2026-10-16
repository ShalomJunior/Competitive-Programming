#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> b(m);
    for (auto& x : b) cin >> x;
    vector<int> c(m);
    for (auto& x : c) cin >> x;
    multiset<int> ma(a.begin(), a.end());
    multiset<pair<int, int>> mb;
    for (int i = 0; i < m; i++) {
        if (c[i]) {
            mb.insert({ b[i], c[i] });
        }
    }
    int ans = 0;
    while (!mb.empty()) {
        int x = mb.begin()->first;
        int up = mb.begin()->second;
        auto it = ma.lower_bound(x);
        if (it == ma.end()) break;
        ans++;
        mb.erase(mb.begin());
        if (up > *it) {
            ma.erase(it);
            ma.insert(up);
        }
    }
    mb.clear();
    for (int i = 0; i < m; i++) {
        if (c[i] == 0) {
            mb.insert({ b[i], c[i] });
        }
    }
    while (!mb.empty()) {
        int x = mb.begin()->first;
        auto it = ma.lower_bound(x);
        if (it == ma.end()) break;
        ans++;
        mb.erase(mb.begin());
        ma.erase(it);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}