#include <bits/stdc++.h>
using namespace std;

struct Data {
    int start;
    int end;
    int len;
    vector<int> par;
    Data(int _start, int _end, int _len, vector<int> _par)
        : start(_start), end(_end), len(_len), par(_par) {
    }
};

Data tree_diameter(const vector<set<int>>& adj) {
    int n = adj.size();

    auto bfs = [&](int start) {
        vector<int> dist(n, -1);
        vector<int> par(n);
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
                    par[u] = node;
                    q.push(u);
                    if (dist[u] > dist[far]) {
                        far = u;
                    }
                }
            }
        }
        int mx = *max_element(dist.begin(), dist.end());
        return Data(start, far, mx, par);
        };

    auto [s, f, l, p] = bfs(0);
    return bfs(f);
}

void solve() {
    int n;
    cin >> n;
    vector<set<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    int ans = 0;
    int diameter = tree_diameter(adj).len;
    int i = 0;
    do {
        i++;
        auto [s, f, l, p] = tree_diameter(adj);
        int u = f;
        while (u != s) {
            int v = p[u];
            adj[u].erase(v);
            adj[v].erase(u);
            adj[f].insert(v);
            adj[v].insert(f);
            u = v;
        }
        int nd = tree_diameter(adj).len;
        cout << i << " -> " << nd << endl;
        if (i == 10) break;
        //if (nd >= diameter) break;
        cout << nd << " " << diameter << endl;
        diameter = nd;
        ans++;
    } while (true);
    cout << ans << endl;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}