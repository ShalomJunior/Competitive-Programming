#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    --a;
    --b;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> vis(n);
    vector<int> par(n);
    vector<int> depth(n);
    function<void(int) > dfs = [&](int r) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                par[c] = r;
                depth[c] = depth[r] + 1;
                dfs(c);
            }
        }
        };
    par[a] = a;
    dfs(a);
    vector<int> o;
    int u = b;
    do {
        o.push_back(u);
        if (u == a) break;
        u = par[u];
    } while (true);
    int m = o.size();
    int i = 0, j = m - 1;
    int res = 0;
    while (i + 1 < j) {
        i++, j--;
        res++;
    }
    vis = vector<bool>(n);
    depth = vector<int>(n);
    for (int i = 0; i < n; i++) {
        assert(vis[i] == false);
    }
    dfs(o[j]);
    int D = 0;
    for (auto& c : depth) D = max(D, c);
    int ans = res + 2 * (n - 1) - D;
    if (i != j) ans++;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
