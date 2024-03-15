#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>>adj(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n);
    vector<int> par(n);
    vector<int> depth(n);
    vector<int> leaves(n);
    vector<int> ends;
    function<void(int)> dfs = [&](int r) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                depth[c] = depth[r] + 1;
                par[c] = r;
                dfs(c);
                leaves[r] += leaves[c];
            }
        }
        if (leaves[r] == 0) {
            ends.push_back(r);
            leaves[r] = 1;
        }
        };
    dfs(0);
    int D = *max_element(depth.begin(), depth.end());
    int LG = log2(D) + 1;
    vector<vector<int>> up(n, vector<int>(LG));
    for (int i = 0; i < n; i++) {
        up[i][0] = par[i];
    }
    for (int j = 1; j < LG; j++) {
        for (int i = 0; i < n; i++) {
            up[i][j] = (up[i][j - 1] == 0 ? 0 : up[up[i][j - 1]][j - 1]);
        }
    }
    int ans = 0;
    int k = ends.size();
    for (int i = 0; i < k; i++) {
        int u = ends[i];
        int moves = depth[u] / 2;
        int meet = u;
        for (int j = LG - 1; j >= 0; j--) {
            if (moves & (1 << j)) {
                meet = up[meet][j];
            }
        }
        if (meet != u) ans = max(ans, leaves[meet]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}