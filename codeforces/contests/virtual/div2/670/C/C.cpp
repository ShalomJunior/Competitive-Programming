#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph {
public:
    struct edge {
        int from;
        int to;
        T cost;
    };

    vector<edge> edges;
    vector<vector<int>> g;
    int n;

    graph(int _n) : n(_n) {
        g.resize(n);
    }

    virtual int add(int from, int to, T cost) = 0;
};

template <typename T>
class forest : public graph<T> {
public:
    using graph<T>::edges;
    using graph<T>::g;
    using graph<T>::n;

    forest(int _n) : graph<T>(_n) {
    }

    int add(int from, int to, T cost = 1) {
        assert(0 <= from && from < n && 0 <= to && to < n);
        int id = (int)edges.size();
        assert(id < n - 1);
        g[from].push_back(id);
        g[to].push_back(id);
        edges.push_back({ from, to, cost });
        return id;
    }
};

template <typename T>
class dfs_forest : public forest<T> {
public:
    using forest<T>::edges;
    using forest<T>::g;
    using forest<T>::n;

    vector<int> pv;
    vector<int> pe;
    vector<int> order;
    vector<int> pos;
    vector<int> end;
    vector<int> sz;
    vector<int> root;
    vector<int> depth;
    vector<T> dist;

    dfs_forest(int _n) : forest<T>(_n) {
    }

    void init() {
        pv = vector<int>(n, -1);
        pe = vector<int>(n, -1);
        order.clear();
        pos = vector<int>(n, -1);
        end = vector<int>(n, -1);
        sz = vector<int>(n, 0);
        root = vector<int>(n, -1);
        depth = vector<int>(n, -1);
        dist = vector<T>(n);
    }

    void clear() {
        pv.clear();
        pe.clear();
        order.clear();
        pos.clear();
        end.clear();
        sz.clear();
        root.clear();
        depth.clear();
        dist.clear();
    }

private:
    void do_dfs(int v) {
        pos[v] = (int)order.size();
        order.push_back(v);
        sz[v] = 1;
        for (int id : g[v]) {
            if (id == pe[v]) {
                continue;
            }
            auto& e = edges[id];
            int to = e.from ^ e.to ^ v;
            depth[to] = depth[v] + 1;
            dist[to] = dist[v] + e.cost;
            pv[to] = v;
            pe[to] = id;
            root[to] = (root[v] != -1 ? root[v] : to);
            do_dfs(to);
            sz[v] += sz[to];
        }
        end[v] = (int)order.size() - 1;
    }

    void do_dfs_from(int v) {
        depth[v] = 0;
        dist[v] = T{};
        root[v] = v;
        pv[v] = pe[v] = -1;
        do_dfs(v);
    }

public:
    void dfs(int v, bool clear_order = true) {
        if (pv.empty()) {
            init();
        }
        else {
            if (clear_order) {
                order.clear();
            }
        }
        do_dfs_from(v);
    }

    void dfs_all() {
        init();
        for (int v = 0; v < n; v++) {
            if (depth[v] == -1) {
                do_dfs_from(v);
            }
        }
        assert((int)order.size() == n);
    }
};

void solve() {
    int n; cin >> n;
    dfs_forest<int> tree(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b; --a, --b;
        tree.add(a, b);
    }
    tree.dfs(0);
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (tree.depth[i] > tree.depth[r]) r = i;
    }
    tree.dfs(r);
    int e = 0;
    for (int i = 0; i < n; i++) {
        if (tree.depth[i] > tree.depth[e]) e = i;
    }
    if (tree.depth[e] % 2 == 0) {
        cout << e << " " << tree.pv[e] << endl;
        cout << e << " " << tree.pv[e] << endl;
        return;
    }
    while (true) {
        e = tree.pv[e];
        if (e == r) break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}