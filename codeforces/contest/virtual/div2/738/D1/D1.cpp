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
    dsu ds1(n), ds2(n);
    for (int i = 0; i < m1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        ds1.join(u, v);
    }
    for (int i = 0; i < m2; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        ds2.join(u, v);
    }
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.push_back({ i, j });
        }
    }
    vector<pair<int, int>> ans;
    for (auto& [u, v] : edges) {
        if (ds1.root(u) != ds1.root(v) && ds2.root(u) != ds2.root(v)) {
            ans.push_back({ u, v });
            ds1.join(u, v);
            ds2.join(u, v);
        }
    }
    cout << ans.size() << endl;
    for (auto& [u, v] : ans) {
        cout << u + 1 << " " << v + 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}