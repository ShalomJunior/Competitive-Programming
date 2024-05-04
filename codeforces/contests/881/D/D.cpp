#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> leaf(n);
    vector<bool> vis(n);
    function<int(int)> dfs = [&](int r) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                leaf[r] += dfs(c);
            }
        }
        if (!leaf[r]) leaf[r] = 1;
        return leaf[r];
        }; dfs(0);
        int q; cin >> q;
        while (q--) {
            int x, y; cin >> x >> y;
            --x, --y;
            cout << leaf[x] * leaf[y] << endl;
        }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}