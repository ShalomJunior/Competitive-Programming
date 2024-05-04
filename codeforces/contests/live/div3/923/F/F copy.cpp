#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
struct Edges {
    int a, b, w;
    bool operator<(const Edges& o)const {
        return w < o.w;
    }
};

class dsu {
public:
    vector<int> parents;
    vector<int> sizes;
    vector<int> cost;
    dsu(int n) {
        parents.resize(n);
        cost.resize(n, INF);
        iota(parents.begin(), parents.end(), 0);
        sizes.resize(n, 1);
    }
    int root(int u) {
        return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v, int w) {
        int a = root(u);
        int b = root(v);
        if (a == b) {
            cost[a] = min({ cost[a], w, cost[b] });
            return 0;
        }
        if (sizes[a] > sizes[b]) swap(a, b);
        parents[a] = b;
        cost[b] = min({ cost[a], w, cost[b] });
        sizes[b] += sizes[a];
        return 1;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    vector<Edges> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        edges[i] = { a, b, w };
        adj[a].push_back({ b, w });
        adj[b].push_back({ a, w });
    }
    sort(edges.begin(), edges.end());
    int cost = INF, boss = -1;
    dsu ds(n);
    for (int i = 0; i < n; i++) {
        auto [a, b, w] = edges[i];
        if (ds.root(a) == ds.root(b)) {
            int r = ds.root(a);
            ds.join(a, b, w);
            if (ds.cost[r] < cost) {
                cost = ds.cost[r];
                boss = r;
            }
        }
        else ds.join(a, b, w);
    }
    int end = -1;
    vector<int> parents(n);
    vector<bool> vis(n);
    function<void(int, int)> dfs = [&](int r, int v) {
        cout << "v = " << v << endl;
        vis[r] = true;
        for (auto& [c, w] : adj[r]) {
            cout << r << " -> " << c << endl;
            if (vis[c]) {
                if (min(v, w) == cost && c == boss) end = r;
            }
            else {
                cout << "c = " << c << endl;
                parents[c] = r;
                dfs(c, min(v, w));
            }
        }
        };
    assert(boss != -1);
    cout << "boss = " << boss << endl;
    cout << "cost = " << cost << endl;
    dfs(boss, INF);
    int k = 0;
    stringstream ss;
    assert(end != -1);
    cout << "end = " << endl;
    do {
        k++;
        ss << end + 1 << " ";
        end = parents[end];
    } while (end != boss);
    ss << boss + 1 << endl;
    cout << cost << " " << k + 1 << endl;
    cout << ss.str() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
