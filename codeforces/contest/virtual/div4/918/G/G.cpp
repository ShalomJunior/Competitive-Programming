#include <bits/stdc++.h>
#define int long long
using namespace std;

const int S = 1000;
const int INF = 1e15;

struct state {
    int t, u, s;
    bool operator<(const state& o) const {
        return t < o.t;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        --x, --y;
        adj[x].push_back({ y, w });
        adj[y].push_back({ x, w });
    }
    vector<int> s(n);
    for (auto& c : s) cin >> c;
    vector<vector<bool>> vis(n, vector<bool>(S + 1));
    vector<vector<int>> time(n, vector<int>(S + 1, INF));
    auto go = [&]() {
        time[0][0] = 0;
        priority_queue<state> pq;
        pq.push({ 0, 0, s[0] });
        time[0][s[0]] = 0;
        while (!pq.empty()) {
            auto [_, u, sp] = pq.top();
            pq.pop();
            if (vis[u][sp])continue;
            vis[u][sp] = true;
            int new_sp = min(sp, s[u]);
            for (auto [v, w] : adj[u]) {
                if (time[u][sp] + new_sp * w < time[v][new_sp]) {
                    time[v][new_sp] = time[u][sp] + new_sp * w;
                    pq.push({ -time[v][new_sp], v, new_sp });
                }
            }
        }
        };
    go();
    int ans = INF;
    for (int i = 0; i <= S; i++) {
        ans = min(ans, time[n - 1][i]);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}