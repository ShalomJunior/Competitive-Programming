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
    cerr << "passed" << endl;
    cerr << x.size() << endl;
    for (auto& c : x) cerr << c << " ";
    cerr << endl;
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
    cerr << "here" << endl;
    return d + 1;
}

void solve() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> all;
    digraph<int> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (a > b) swap(a, b);
        all.insert({ a, b });
    }
    for (auto [u, v] : all)
        g.add(u, v);
    cout << find_topsort(g) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}