#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
struct state {
    int v;
    int d;
    int combo;
    bool operator>(const state& other) const {
        return d > other.d;
    }
};

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<bool> comb(n);
    for (int i = 0; i < h; i++) {
        int p;
        cin >> p;
        comb[p - 1] = true;
    }
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }
    auto djikstra = [&](int root) {
        priority_queue<state, vector<state>, greater<state>> pq;
        vector<vector<int>> dis(2, vector<int>(n, INF));
        vector<vector<bool>> vis(2, vector<bool>(n));
        pq.push({ root, 0, 0 });
        dis[0][root] = 0;
        while (!pq.empty()) {
            auto [u, d, b] = pq.top();
            pq.pop();
            if (vis[b][u]) continue;
            vis[b][u] = true;
            for (auto& [v, w] : adj[u]) {
                int nd = d + (b || comb[u] ? w / 2 : w);
                if (nd < dis[b || comb[u]][v]) {
                    dis[b || comb[u]][v] = nd;
                    pq.push({ v, nd, (b || comb[u]) });
                }
            }
        }
        return dis;
        };
    auto x = djikstra(0);
    auto y = djikstra(n - 1);
    int ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, max(min(x[0][i], x[1][i]), min(y[0][i], y[1][i])));
    }
    cout << (ans == INF ? -1 : ans) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}