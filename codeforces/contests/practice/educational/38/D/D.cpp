#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        adj[u].push_back({ v, w * 2 });
        adj[v].push_back({ u, w * 2 });
    }
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> dis(n);
    auto work = [&]() {
        vector<bool> b(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for (int i = 0; i < n; i++) {
            dis[i] = a[i];
            pq.push({ -dis[i], i });
        }
        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            cost *= -1;
            if (b[u]) continue;
            b[u] = true;
            for (auto& [v, w] : adj[u]) {
                if (dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                    pq.push({ -dis[v], v });
                }
            }
        }
        };
    work();
    for (auto& c : dis) cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
