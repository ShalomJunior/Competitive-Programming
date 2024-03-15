#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n + 1);
    set<int> sp, sq;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        a[c].push_back(i);
        if (a[c].size() > 2) { cout << "NO" << endl; return; }
        sp.insert(i + 1);
        sq.insert(i + 1);
    }
    vector<int> p(n), q(n);
    for (int i = 1; i <= n; i++) {
        if (a[i].size() == 2) {
            p[a[i][0]] = i; sp.erase(i);
            q[a[i][1]] = i; sq.erase(i);
        }
    }
    for (int i = n; i > 0; i--) {
        if (a[i].size() != 1) continue;
        int j = a[i][0];
        auto f = sp.upper_bound(i);
        auto s = sq.upper_bound(i);
        if (f != sp.begin()) {
            q[j] = i; sq.erase(i);
            p[j] = *prev(f); sp.erase(p[j]);
        }
        else if (s != sq.end()) {
            p[j] = i; sp.erase(i);
            q[j] = *prev(s); sq.erase(q[j]);
        }
        else {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        if (p[i] && !q[i]) {
            auto it = sq.upper_bound(p[i]);
            if (it == sq.begin()) { cout << "NO" << endl; return; }
            q[i] = *prev(it); sq.erase(q[i]);
        }
        else if (!p[i] && q[i]) {
            auto it = sp.upper_bound(q[i]);
            if (it == sp.begin()) { cout << "NO" << endl; return; }
            p[i] = *prev(it); sp.erase(p[i]);
        }
    }
    auto print = [&](vector<int>& v) {
        for (auto& c : v) cout << c << " ";
        cout << endl;
        };
    cout << "YES" << endl;
    print(p), print(q);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}