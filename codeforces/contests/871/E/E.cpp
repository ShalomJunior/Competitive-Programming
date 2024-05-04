#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<vector<bool>> vis;

bool in(int i, int j) { return (i >= 0 && i < n && j >= 0 && j < m); }

int dfs(int i, int j) {
    vis[i][j] = true;
    if (adj[i][j] == 0) return 0;

    int ans = adj[i][j];
    if (in(i + 1, j) && !vis[i + 1][j]) ans += dfs(i + 1, j);
    if (in(i - 1, j) && !vis[i - 1][j]) ans += dfs(i - 1, j);
    if (in(i, j + 1) && !vis[i][j + 1]) ans += dfs(i, j + 1);
    if (in(i, j - 1) && !vis[i][j - 1]) ans += dfs(i, j - 1);

    return ans;
}

void solve() {
    cin >> n >> m;
    adj.resize(n);
    vis.resize(n);
    for (int i = 0; i < n; i++) {
        adj[i].resize(m);
        vis[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> adj[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        adj.clear();
        vis.clear();
        solve();
    }
}