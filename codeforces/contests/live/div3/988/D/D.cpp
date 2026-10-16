#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, L;
    cin >> n >> m >> L;
    vector<pair<int, int>> p(n);
    for (auto& [l, r] : p) cin >> l >> r;
    vector<int> x(m), v(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> v[i];
    }
    int j = 0;
    int s = 1;
    multiset<int> in, nxt;
    for (auto& [l, r] : p) {
        int len = r - l + 1;
        while (j < m && x[j] < l) {
            nxt.insert(v[j]);
            j++;
        }
        while (s <= len) {
            if (nxt.empty()) {
                cout << -1 << endl;
                return;
            }
            in.insert(*prev(nxt.end()));
            s += *prev(nxt.end());
            nxt.erase(prev(nxt.end()));
        }
    }
    cout << in.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
