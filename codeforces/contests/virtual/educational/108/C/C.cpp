#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> u(n), s(n);
    for (auto& c : u) cin >> c;
    for (auto& c : s) cin >> c;
    map<int, vector<int>> g;
    for (int i = 0; i < n; i++) {
        g[u[i]].push_back(s[i]);
    }
    for (auto& [id, v] : g) {
        sort(v.begin(), v.end());
    }
    int tot = 0;
    int lost = 0;
    map<int, int> keep;
    for (int k = 1; k <= n; k++) {
        vector<int> to_del;
        for (auto& [id, v] : g) {
            if (v.empty()) {
                lost += keep[id];
                to_del.push_back(id);
            }
            else {
                tot += v.back();
                v.pop_back();
            }""
        }
        cout << tot - lost << " ";
        for (auto& id : to_del) g.erase(id);
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
