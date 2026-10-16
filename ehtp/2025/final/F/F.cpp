#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        --a;
        --b;
        adj[a].push_back({ b, w });
        adj[b].push_back({ a, w });
    }
    int x;
    cin >> x;
    set<int> p;
    for (int i = 0; i < x; i++) {
        int j;
        cin >> j;
        p.insert(j - 1);
    }
    int start;
    cin >> start;
    start--;
    auto bfs = [&](int r) {
        vector<bool> vis(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, r });
        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (p.count(u)) return cost;
            if (vis[u]) continue;
            vis[u] = true;
            for (auto& [v, w] : adj[u]) {
                if (!vis[v]) {
                    pq.push({ cost + w, v });
                }
            }
        }
        return INF;
        };
    int ans = bfs(start);
    cout << (ans == INF ? -1 : ans) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}