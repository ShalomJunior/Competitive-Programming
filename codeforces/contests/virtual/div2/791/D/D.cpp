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
class digraph : public graph<T> {
public:
    using graph<T>::edges;
    using graph<T>::g;
    using graph<T>::n;

    digraph(int _n) : graph<T>(_n) {
    }

    int add(int from, int to, T cost = 1) {
        assert(0 <= from && from < n && 0 <= to && to < n);
        int id = (int)edges.size();
        g[from].push_back(id);
        edges.push_back({ from, to, cost });
        return id;
    }

    digraph<T> reverse() const {
        digraph<T> rev(n);
        for (auto& e : edges) {
            rev.add(e.to, e.from, e.cost);
        }
        return rev;
    }
};

template <typename T>
int find_topsort(const graph<T>& g) {
    vector<int> deg(g.n, 0);
    for (int id = 0; id < (int)g.edges.size(); id++) {
        deg[g.edges[id].to]++;
    }
    vector<int> x;
    for (int i = 0; i < g.n; i++) {
        if (deg[i] == 0) {
            x.push_back(i);
        }
    }
    for (int ptr = 0; ptr < (int)x.size(); ptr++) {
        int i = x[ptr];
        for (int id : g.g[i]) {
            auto& e = g.edges[id];
            int to = e.to;
            if (--deg[to] == 0) {
                x.push_back(to);
            }
        }
    }
    if ((int)x.size() != g.n) return 0;
    if (x.empty()) return -1;
    vector<int> dis(g.n, 0);
    for (int i : x) {
        for (int id : g.g[i]) {
            auto& e = g.edges[id];
            int to = e.to;
            dis[to] = max(dis[to], dis[i] + 1);
        }
    }
    int d = *max_element(dis.begin(), dis.end());
    return d + 1;
}

void solve() {
    int n, m;
    long long k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    digraph<int> g(n);
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = { u - 1, v - 1 };
        g.add(u - 1, v - 1);
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        return  a[i] < a[j];
        });
    vector<int> pos(n);
    for (int i = 0; i < n; i++) pos[p[i]] = i;
    auto check = [&](int mid) {
        digraph<int> graph(n);
        for (auto& [u, v] : edges) {
            if (pos[u] <= mid && pos[v] <= mid) {
                graph.add(u, v);
            }
        }
        int z = find_topsort(graph);
        if (z == 0) return true;
        if (z == -1 && k == 1) return true;
        return z >= k;
        };
    int L = 0, R = n - 1;
    while (L < R) {
        int mid = (L + R) / 2;
        check(mid) ? R = mid : L = mid + 1;
    }
    cout << (L == R && check(L) ? a[p[L]] : -1) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

// #include <bits/stdc++.h>
// #define int long long
// using namespace std;

// const int INF = 1e18;
// vector<int> calculateInDegrees(const vector<vector<int>>& graph) {
//     int n = graph.size();
//     vector<int> inDegrees(n, 0);
//     for (int u = 0; u < n; ++u) {
//         for (int v : graph[u]) {
//             inDegrees[v]++;
//         }
//     }
//     return inDegrees;
// }

// vector<int> topologicalSort(const vector<vector<int>>& graph) {
//     int n = graph.size();
//     vector<int> inDegrees = calculateInDegrees(graph);
//     queue<int> zeroInDegree;
//     for (int i = 0; i < n; ++i) {
//         if (inDegrees[i] == 0) {
//             zeroInDegree.push(i);
//         }
//     }
//     vector<int> sortedOrder;
//     while (!zeroInDegree.empty()) {
//         int u = zeroInDegree.front();
//         zeroInDegree.pop();
//         sortedOrder.push_back(u);
//         for (int v : graph[u]) {
//             inDegrees[v]--;
//             if (inDegrees[v] == 0) {
//                 zeroInDegree.push(v);
//             }
//         }
//     }
//     if (sortedOrder.size() != n) {
//         return vector<int>();
//     }
//     return sortedOrder;
// }

// void solve() {
//     int n, m, k;
//     cin >> n >> m >> k;
//     vector<int> a(n);
//     for (auto& c : a) cin >> c;
//     vector<vector<int>> adj(n);
//     for (int i = 0; i < m; i++) {
//         int u, v;
//         cin >> u >> v;
//         adj[u - 1].push_back(v - 1);
//     }
//     vector<int> p(n);
//     iota(p.begin(), p.end(), 0);
//     sort(p.begin(), p.end(), [&](int i, int j) {
//         return  a[i] < a[j];
//         });
//     vector<int> pos(n);
//     for (int i = 0; i < n; i++) pos[p[i]] = i;
//     auto check = [&](int mid) {
//         vector<vector<int>> graph(n);
//         for (int i = 0; i < n; i++) {
//             if (pos[i] > mid)continue;
//             for (auto& c : adj[i]) {
//                 if (pos[c] <= mid)graph[i].push_back(c);
//             }
//         }
//         int z = 0;
//         for (auto& c : topologicalSort(graph)) {
//             if (pos[c] <= mid) {
//                 z++;
//                 cout << c << " ";
//             }
//         }
//         cout << endl;
//         cerr << "z = " << z << endl;
//         return (z ? z >= k : true);
//         };
//     int L = 0, R = n - 1;
//     while (L < R) {
//         int mid = (L + R) / 2;
//         cerr << " mid =  " << mid << endl;
//         check(mid) ? R = mid : L = mid + 1;
//     }
//     cout << (L < k - 1 ? -1 : a[p[L]]) << endl;
// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     solve();
// }
