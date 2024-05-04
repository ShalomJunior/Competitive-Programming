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

template <typename T>
class lca_forest : public dfs_forest<T> {
public:
    using dfs_forest<T>::edges;
    using dfs_forest<T>::g;
    using dfs_forest<T>::n;
    using dfs_forest<T>::pv;
    using dfs_forest<T>::pos;
    using dfs_forest<T>::end;
    using dfs_forest<T>::depth;
    using dfs_forest<T>::dist;

    int h;
    vector<vector<int>> pr;
    vector<vector<int>> sp;

    lca_forest(int _n) : dfs_forest<T>(_n) {
    }

    inline void build_lca() {
        assert(!pv.empty());
        int max_depth = 0;
        for (int i = 0; i < n; i++) {
            max_depth = max(max_depth, depth[i]);
        }
        h = 1;
        while ((1 << h) <= max_depth) {
            h++;
        }
        pr.resize(n);
        sp.resize(n);
        for (int i = 0; i < n; i++) {
            pr[i].resize(h);
            sp[i].resize(h);
            pr[i][0] = pv[i];
            sp[i][0] = dist[i] - (pv[i] == -1 ? 0 : dist[pv[i]]);
        }
        for (int j = 1; j < h; j++) {
            for (int i = 0; i < n; i++) {
                pr[i][j] = (pr[i][j - 1] == -1 ? -1 : pr[pr[i][j - 1]][j - 1]);
                sp[i][j] = max(sp[i][j - 1], pr[i][j - 1] == -1 ? 0 : sp[pr[i][j - 1]][j - 1]);
            }
        }
    }

    inline bool anc(int x, int y) {
        return (pos[x] <= pos[y] && end[y] <= end[x]);
    }

    inline int go_up(int x, int up, int& w) {
        assert(!pr.empty());
        up = min(up, (1 << h) - 1);
        for (int j = h - 1; j >= 0; j--) {
            if (up & (1 << j)) {
                w = max(w, sp[x][j]);
                x = pr[x][j];
                if (x == -1) {
                    break;
                }
            }
        }
        return x;
    }

    inline int lca(int x, int y) {
        assert(!pr.empty());
        if (anc(x, y)) {
            return x;
        }
        if (anc(y, x)) {
            return y;
        }
        for (int j = h - 1; j >= 0; j--) {
            if (pr[x][j] != -1 && !anc(pr[x][j], y)) {
                x = pr[x][j];
            }
        }
        return pr[x][0];
    }
};

struct Edge {
    int u, v, w, index;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    vector<pair<int, int>> order;
    for (int i = 0; i < m; i++) {
        auto& [u, v, w, index] = edges[i];
        cin >> u >> v >> w;
        --u, --v;
        index = i;
    }
    dsu ds(n);
    sort(edges.begin(), edges.end());
    long long tot = 0;
    lca_forest<long long> tree(n);
    int cnt = 0;
    for (auto& [u, v, w, _] : edges) {
        int a = ds.root(u);
        int b = ds.root(v);
        if (a != b) {
            ds.join(u, v);
            tree.add(u, v, w);
            tot += w;
            cnt++;
        }
    }
    assert(cnt == n - 1);
    tree.dfs(0);
    tree.build_lca();
    vector<long long> ans(m);
    for (auto& [u, v, w, index] : edges) {
        int r = tree.lca(u, v);
        int du = tree.depth[u];
        int dv = tree.depth[v];
        int dr = tree.depth[r];
        int mx = 0;
        tree.go_up(u, du - dr, mx);
        tree.go_up(v, dv - dr, mx);
        ans[index] = tot + w - mx;
    }
    for (auto& c : ans) cout << c << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}



// #include <bits/stdc++.h>
// using namespace std;

// class dsu {
// public:
//     vector<int> parents;
//     vector<int> sizes;
//     dsu(int n) {
//         parents.resize(n);
//         iota(parents.begin(), parents.end(), 0);
//         sizes.resize(n, 1);
//     }
//     int root(int u) {
//         return parents[u] == u ? u : parents[u] = root(parents[u]);
//     }
//     bool join(int u, int v) {
//         int a = root(u);
//         int b = root(v);
//         if (a == b) return 0;
//         if (sizes[a] > sizes[b]) swap(a, b);
//         parents[a] = b;
//         sizes[b] += sizes[a];
//         return 1;
//     }
// };

// template <typename T>
// class graph {
// public:
//     struct edge {
//         int from;
//         int to;
//         T cost;
//     };

//     vector<edge> edges;
//     vector<vector<int>> g;
//     int n;

//     graph(int _n) : n(_n) {
//         g.resize(n);
//     }

//     virtual int add(int from, int to, T cost) = 0;
// };

// template <typename T>
// class forest : public graph<T> {
// public:
//     using graph<T>::edges;
//     using graph<T>::g;
//     using graph<T>::n;

//     forest(int _n) : graph<T>(_n) {
//     }

//     int add(int from, int to, T cost = 1) {
//         assert(0 <= from && from < n && 0 <= to && to < n);
//         int id = (int)edges.size();
//         assert(id < n - 1);
//         g[from].push_back(id);
//         g[to].push_back(id);
//         edges.push_back({ from, to, cost });
//         return id;
//     }
// };

// template <typename T>
// class dfs_forest : public forest<T> {
// public:
//     using forest<T>::edges;
//     using forest<T>::g;
//     using forest<T>::n;

//     vector<int> pv;
//     vector<int> pe;
//     vector<int> order;
//     vector<int> pos;
//     vector<int> end;
//     vector<int> sz;
//     vector<int> root;
//     vector<int> depth;
//     vector<T> dist;

//     dfs_forest(int _n) : forest<T>(_n) {
//     }

//     void init() {
//         pv = vector<int>(n, -1);
//         pe = vector<int>(n, -1);
//         order.clear();
//         pos = vector<int>(n, -1);
//         end = vector<int>(n, -1);
//         sz = vector<int>(n, 0);
//         root = vector<int>(n, -1);
//         depth = vector<int>(n, -1);
//         dist = vector<T>(n);
//     }

//     void clear() {
//         pv.clear();
//         pe.clear();
//         order.clear();
//         pos.clear();
//         end.clear();
//         sz.clear();
//         root.clear();
//         depth.clear();
//         dist.clear();
//     }

// private:
//     void do_dfs(int v) {
//         pos[v] = (int)order.size();
//         order.push_back(v);
//         sz[v] = 1;
//         for (int id : g[v]) {
//             if (id == pe[v]) {
//                 continue;
//             }
//             auto& e = edges[id];
//             int to = e.from ^ e.to ^ v;
//             depth[to] = depth[v] + 1;
//             dist[to] = dist[v] + e.cost;
//             pv[to] = v;
//             pe[to] = id;
//             root[to] = (root[v] != -1 ? root[v] : to);
//             do_dfs(to);
//             sz[v] += sz[to];
//         }
//         end[v] = (int)order.size() - 1;
//     }

//     void do_dfs_from(int v) {
//         depth[v] = 0;
//         dist[v] = T{};
//         root[v] = v;
//         pv[v] = pe[v] = -1;
//         do_dfs(v);
//     }

// public:
//     void dfs(int v, bool clear_order = true) {
//         if (pv.empty()) {
//             init();
//         }
//         else {
//             if (clear_order) {
//                 order.clear();
//             }
//         }
//         do_dfs_from(v);
//     }

//     void dfs_all() {
//         init();
//         for (int v = 0; v < n; v++) {
//             if (depth[v] == -1) {
//                 do_dfs_from(v);
//             }
//         }
//         assert((int)order.size() == n);
//     }
// };

// template <typename T>
// class lca_forest : public dfs_forest<T> {
// public:
//     using dfs_forest<T>::edges;
//     using dfs_forest<T>::g;
//     using dfs_forest<T>::n;
//     using dfs_forest<T>::pv;
//     using dfs_forest<T>::pos;
//     using dfs_forest<T>::end;
//     using dfs_forest<T>::depth;
//     using dfs_forest<T>::dist;

//     int h;
//     vector<vector<int>> pr;
//     vector<vector<int>> sp;

//     lca_forest(int _n) : dfs_forest<T>(_n) {
//     }

//     inline void build_lca() {
//         assert(!pv.empty());
//         int max_depth = 0;
//         for (int i = 0; i < n; i++) {
//             max_depth = max(max_depth, depth[i]);
//         }
//         h = 1;
//         while ((1 << h) <= max_depth) {
//             h++;
//         }
//         pr.resize(n);
//         sp.resize(n);
//         for (int i = 0; i < n; i++) {
//             pr[i].resize(h);
//             sp[i].resize(h);
//             pr[i][0] = pv[i];
//             sp[i][0] = dist[i] - (pv[i] == -1 ? 0 : dist[pv[i]]);
//             cerr << sp[i][0] << " ";
//         }
//         cerr << endl;
//         for (int j = 1; j < h; j++) {
//             for (int i = 0; i < n; i++) {
//                 pr[i][j] = (pr[i][j - 1] == -1 ? -1 : pr[pr[i][j - 1]][j - 1]);
//                 sp[i][j] = max(sp[i][j - 1], pr[i][j - 1] == -1 ? 0 : sp[pr[i][j - 1]][j - 1]);
//             }
//         }
//     }

//     inline bool anc(int x, int y) {
//         return (pos[x] <= pos[y] && end[y] <= end[x]);
//     }

//     inline int go_up(int x, int up, int& w) {
//         assert(!pr.empty());
//         up = min(up, (1 << h) - 1);
//         for (int j = h - 1; j >= 0; j--) {
//             if (up & (1 << j)) {
//                 w = max(w, sp[x][j]);
//                 x = pr[x][j];
//                 if (x == -1) {
//                     break;
//                 }
//             }
//         }
//         return x;
//     }

//     inline int lca(int x, int y) {
//         assert(!pr.empty());
//         if (anc(x, y)) {
//             return x;
//         }
//         if (anc(y, x)) {
//             return y;
//         }
//         for (int j = h - 1; j >= 0; j--) {
//             if (pr[x][j] != -1 && !anc(pr[x][j], y)) {
//                 x = pr[x][j];
//             }
//         }
//         return pr[x][0];
//     }
// };

// struct Edge {
//     int u, v, w, index;
//     bool operator<(const Edge& other) const {
//         return w < other.w;
//     }
// };

// void solve() {
//     int n, m;
//     cin >> n >> m;
//     vector<Edge> edges(m);
//     vector<pair<int, int>> order;
//     for (int i = 0; i < m; i++) {
//         auto& [u, v, w, index] = edges[i];
//         cin >> u >> v >> w;
//         --u, --v;
//         index = i;
//     }
//     dsu ds(n);
//     sort(edges.begin(), edges.end());
//     long long tot = 0;
//     lca_forest<int> tree(n);
//     cerr << "where" << endl;
//     int cnt = 0;
//     for (auto& [u, v, w, _] : edges) {
//         int a = ds.root(u);
//         int b = ds.root(v);
//         if (a != b) {
//             ds.join(u, v);
//             tree.add(u, v, w);
//             tot += w;
//             cnt++;
//         }
//     }
//     assert(cnt == n - 1);
//     cerr << "tot =  " << tot << endl;
//     cerr << "start" << endl;
//     tree.dfs(0);
//     cerr << "lca" << endl;
//     tree.build_lca();
//     cerr << "end" << endl;
//     vector<int> ans(m);
//     for (auto& [u, v, w, index] : edges) {
//         cerr << u << " " << v << " " << w << endl;
//         int r = tree.lca(u, v);
//         int du = tree.depth[u];
//         int dv = tree.depth[v];
//         int dr = tree.depth[r];
//         cerr << u << " " << v << " " << r << endl;
//         cerr << du << " " << dv << " " << dr << endl;
//         int mx = 0;

//         tree.go_up(u, du - dr, mx);
//         cerr << "mx " << mx << endl;

//         tree.go_up(v, dv - dr, mx);
//         cerr << "mx = " << mx << endl;
//         ans[index] = tot + w - mx;
//     }
//     for (auto& c : ans) cout << c << endl;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     solve();
// }
