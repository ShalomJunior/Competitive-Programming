#include <bits/stdc++.h>
using namespace std;

struct BridgeTree {
    int n, timer = 0;
    vector<vector<int>> adj;
    vector<int> tin, low;
    vector<bool> visited;
    vector<pair<int, int>> bridges;
    vector<int> component;
    vector<vector<int>> tree;

    BridgeTree(int n) : n(n), adj(n), tin(n, -1), low(n, -1), visited(n, false), component(n, -1) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void find_bridges(int v, int p) {
        visited[v] = true;
        tin[v] = low[v] = timer++;
        for (int to : adj[v]) {
            if (to == p) continue;
            if (visited[to]) {
                low[v] = min(low[v], tin[to]);
            }
            else {
                find_bridges(to, v);
                low[v] = min(low[v], low[to]);
                if (low[to] > tin[v]) {
                    bridges.emplace_back(v, to);
                }
            }
        }
    }

    void dfs_bcc(int v, int comp_id) {
        component[v] = comp_id;
        for (int to : adj[v]) {
            if (component[to] == -1 && !is_bridge(v, to)) {
                dfs_bcc(to, comp_id);
            }
        }
    }

    bool is_bridge(int u, int v) {
        return tin[u] < low[v] || tin[v] < low[u];
    }

    void build_bridge_tree() {
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                find_bridges(i, -1);
            }
        }

        int comp_id = 0;
        fill(component.begin(), component.end(), -1);
        for (int i = 0; i < n; i++) {
            if (component[i] == -1) {
                dfs_bcc(i, comp_id++);
            }
        }

        tree.resize(comp_id);
        for (auto& [u, v] : bridges) {
            int cu = component[u], cv = component[v];
            if (cu != cv) {
                tree[cu].push_back(cv);
                tree[cv].push_back(cu);
            }
        }
    }

    vector<int> get_bcc_sizes() {
        vector<int> sizes(tree.size(), 0);
        for (int i = 0; i < n; i++) {
            sizes[component[i]]++;
        }
        return sizes;
    }
};

int tree_diameter(const vector<vector<int>>& adj) {
    int n = adj.size();
    if (n == 1) return 0;

    auto bfs = [&](int start) {
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        int far = start;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int u : adj[node]) {
                if (dist[u] == -1) {
                    dist[u] = dist[node] + 1;
                    q.push(u);
                    if (dist[u] > dist[far]) {
                        far = u;
                    }
                }
            }
        }
        return make_pair(far, dist[far]);
        };

    int nodeA = bfs(0).first;
    return bfs(nodeA).second;
}

void solve() {
    int n, m;
    cin >> n >> m;
    BridgeTree bt(n);
    vector<pair<int, int>> e(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        bt.add_edge(u, v);
        e[i] = { u, v };
    }
    bt.build_bridge_tree();
    vector<int> sizes = bt.get_bcc_sizes();
    int z = sizes.size();
    cout << z - tree_diameter(bt.tree) - 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
