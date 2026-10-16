#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
struct info {
    int d;
    int b;
    int u;
    bool operator<(const info& o) const {
        if (d != o.d) return d > o.d;
        if (b != o.b) return b > o.b;
        return u < o.u;
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }
    int ans = k;
    vector<int> y(n, INF);
    for (int i = 0; i < k; i++) {
        int v, w;
        cin >> v >> w;
        --v;
        y[v] = min(y[v], w);
    }
    auto bfs = [&](int root) {
        vector<int> dis(n, INF);
        vector<bool> vis(n);
        priority_queue<info> pq;
        pq.push({ 0, 0, root });
        for (int i = 0; i < n; i++) {
            if (y[i] != INF) {
                dis[i] = y[i];
                pq.push({ y[i], 1, i });
            }
        }
        dis[root] = 0;
        while (!pq.empty()) {
            auto [d, b, u] = pq.top();
            pq.pop();
            if (vis[u]) continue;
            vis[u] = true;
            if (b == 1) ans--;
            for (auto& [c, w] : adj[u]) {
                if (!vis[c] && dis[c] >= dis[u] + w) {
                    dis[c] = dis[u] + w;
                    pq.push({ dis[c], 0, c });
                }
            }
        }
        };
    bfs(0);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
