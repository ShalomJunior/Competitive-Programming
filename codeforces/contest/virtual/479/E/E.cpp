#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    vector<bool> vis(n);
    vector<int> con;
    function<void(int)> dfs = [&](int r) {
        vis[r] = true;
        con.push_back(r);
        for (auto& c : adj[r]) {
            if (!vis[c]) dfs(c);
        }
        };

    function<bool(int, int, vector<bool>&)> go = [&](int r, int p, vector<bool>& done) {
        done[r] = true;
        bool ans = false;
        for (auto& c : adj[r]) {
            if (done[c] && c != p) ans = true;
            else if (!done[c]) ans |= go(c, r, done);
        }
        return ans;
        };

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        con.clear();
        dfs(i);
        bool bad = false;
        for (auto& r : con) {
            if (adj[r].size() != 2) { bad = true; break; }
        }
        if (bad) continue;
        vector<bool> done(n);
        if (go(con[0], -1, done)) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}