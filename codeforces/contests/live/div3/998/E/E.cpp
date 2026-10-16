#include <bits/stdc++.h>
using namespace std;

class dsu {
public:
    vector<int> parents;
    vector<int> sizes;
    dsu(int n) {
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
        sizes.resize(n, 1);
    }
    int root(int u) {
        return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v) {
        int a = root(u);
        int b = root(v);
        if (a == b) return 0;
        if (sizes[a] > sizes[b]) swap(a, b);
        parents[a] = b;
        sizes[b] += sizes[a];
        return 1;
    }
};

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<pair<int, int>> f(m1), g(m2);
    for (auto& [u, v] : f) {
        cin >> u >> v;
        u--;
        v--;
    }
    dsu G(n);
    for (auto& [u, v] : g) {
        cin >> u >> v;
        u--;
        v--;
        G.join(u, v);
    }
    int ans = 0;
    dsu F(n);
    for (auto& [u, v] : f) {
        if (G.root(u) != G.root(v)) ans++;
        else {
            F.join(u, v);
        }
    }
    set<int> r;
    for (int i = 0; i < n; i++) r.insert(F.root(i));
    map<int, int> cnt;
    for (auto& p : r) cnt[G.root(p)]++;
    for (auto& [k, v] : cnt) ans += v - 1;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
