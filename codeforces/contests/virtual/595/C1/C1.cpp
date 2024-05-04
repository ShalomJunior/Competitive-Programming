#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
set<int> s;

void prepare() {
    vector<int> p;
    for (int i = 0; pow(3, i) < N; i++) {
        p.push_back(pow(3, i));
    }
    function <void(int, int)> go = [&](int i, int cum) {
        if (i == p.size()) return;
        s.insert(cum + p[i]);
        go(i + 1, cum + p[i]);
        go(i + 1, cum);
        };
    go(0, 0);
}

void solve() {
    int n; cin >> n;
    auto it = s.lower_bound(n);
    cout << *it << endl;
}

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--) solve();
}