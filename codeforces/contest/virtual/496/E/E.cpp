#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, s;
    cin >> n >> m >> s; --s;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
    }
    vector<bool> vis(n);
    function<void(int)> dfs = [&](int r) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) dfs(c);
        }
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) { dfs(i); ans++; }
    }
    cout << ans - 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}