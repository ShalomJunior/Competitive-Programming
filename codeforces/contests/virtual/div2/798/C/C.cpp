#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    vector<bool> vis(n);
    vector<bool> leaf(n);
    vector<int> par(n);
    vector<int> child(n);
    vector<int> depth(n);
    function<void(int)> dfs = [&](int r) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                par[c] = r;
                depth[c] = depth[r] + 1;
                child[r]++;
                dfs(c);
            }
        }
        leaf[r] = child[r] == 0;
        };
    auto go = [&](int u) {
        int cnt = n;
        do {
            cnt--;
            if (par[u] == u) break;
            if (child[par[u]] == 2) cnt--;
            u = par[u];
        } while (true);
        ans = max(ans, cnt);
        };
    dfs(0);
    int u = -1;
    int d = 1e7;
    for (int i = 1; i < n; i++) {
        if (child[par[i]] == 1) {
            if (d > depth[i]) {
                u = i;
                d = depth[i];
            }
        }
    }
    if (u != -1) go(u);
    u = -1;
    d = 1e7;
    for (int i = 0; i < n; i++) {
        if (leaf[i]) {
            if (d > depth[i]) {
                u = i;
                d = depth[i];
            }
        }
    }
    if (u != -1) go(u);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}