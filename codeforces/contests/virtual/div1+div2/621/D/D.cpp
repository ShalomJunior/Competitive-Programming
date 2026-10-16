#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto bfs = [&](int root) {
        vector<bool> vis(n);
        vector<int> dis(n);
        priority_queue<pair<int, int>> pq;
        pq.push({ 0, root });
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            d = -d;
            pq.pop();
            if (vis[u]) continue;
            vis[u] = true;
            dis[u] = d;
            for (auto& c : adj[u]) {
                if (!vis[c]) {
                    pq.push({ -(d + 1), c });
                }
            }
        }
        return dis;
        };
    auto x = bfs(0);
    auto y = bfs(n - 1);
    vector<pair<int, int>> p(k);
    multiset<int> ms;
    for (int i = 0; i < k; i++) {
        p[i] = { x[a[i]], y[a[i]] };
        ms.insert(p[i].second);
    }
    sort(p.begin(), p.end(), [&](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.first - p1.second < p2.first - p2.second;
        });
    int ans = 0;
    for (auto& [l, r] : p) {
        ms.erase(ms.find(r));
        if (ms.empty()) break;
        ans = max(ans, 1 + l + *prev(ms.end()));
    }
    cout << min(ans, x[n - 1]) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}