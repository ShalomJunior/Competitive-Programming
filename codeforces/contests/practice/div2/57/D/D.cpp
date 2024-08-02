#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    int tot = 0;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 1; i < n; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        adj[a].push_back({ b, w });
        adj[b].push_back({ a, w });
        tot += w;
    }
    int mx = 0;
    vector<bool> vis(n);
    function<void(int, int)> dfs = [&](int r, int cost) {
        vis[r] = true;
        int cnt = 0;
        for (auto [c, w] : adj[r]) {
            if (!vis[c]) {
                cnt++;
                dfs(c, cost + w);
            }
        }
        if (cnt == 0) mx = max(mx, cost);
        };
    dfs(0, 0);
    cout << tot * 2 - mx << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}