#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q, x; cin >> q >> x;
    set<int> s;
    for (int i = 0; i < x; i++) s.insert(i);
    multiset<int> stage;
    vector<vector<int>> r(x);
    for (int i = 0; i < q; i++) {
        int c; cin >> c;
        r[c % x].push_back(c);
        s.erase(c % x);
        if (!s.empty()) {
            cout << *s.begin() << endl;
            continue;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}