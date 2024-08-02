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
    int n, m;
    cin >> n >> m;
    if (m == 0) {
        cout << n % 2 << endl;
        return;
    }
    vector<pair<int, int>> c(m);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        c[i] = { a, b };
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    set<int> r;
    for (int i = 0; i < n; i++) r.insert(i);
    dsu X(n), Y(n);
    int x = c[0].first;
    int y = c[0].second;
    queue<pair<int, int>> q;
    q.push({ c[0].first, 0 });
    while (!q.empty()) {
        auto [u, id] = q.front();
        q.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}