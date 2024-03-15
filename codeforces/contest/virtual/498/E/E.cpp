#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int p; cin >> p; --p;
        adj[p].push_back(i);
    }
    for (auto& vec : adj) sort(vec.begin(), vec.end());
    vector<int> ans, child(n), id(n);
    vector<bool> vis(n);
    function<int(int)> Dfs = [&](int r) {
        vis[r] = true;
        child[r] = 1;
        id[r] = ans.size();
        ans.push_back(r);
        for (auto& c : adj[r]) child[r] += Dfs(c);
        return child[r];
        };
    Dfs(0);
    while (q--) {
        int u, k; cin >> u >> k; --u;
        int i = id[u];
        cout << (k > child[u] ? -1 : 1 + ans[i + k - 1]) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}