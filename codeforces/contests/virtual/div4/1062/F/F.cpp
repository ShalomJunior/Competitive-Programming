#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> tree(n);
    vector<int> par(n, -1);
    vector<int> cnt(n, 1);
    vector<int> under(n);
    vector<int> zoo(n);
    vector<bool> vis(n);
    function<void(int)> dfs = [&](int r) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                par[c] = r;
                tree[r].push_back(c);
                dfs(c);
                zoo[r] += zoo[c];
                cnt[r] += cnt[c];
                under[r] += cnt[c];
            }
        }
        if (cnt[r] >= k) zoo[r]++;
        };
    dfs(0);
    vector<int> ans(n);
    ans[0] = zoo[0];
    function<void(int)> go = [&](int r) {
        if (r != 0) {
            int p = par[r];
            ans[r] = ans[p];
            if (cnt[r] < k) ans[r]++;
            if (n - cnt[r] < k) ans[r]--;
        }
        for (auto& c : tree[r]) go(c);
        };
    go(0);
    cout << accumulate(ans.begin(), ans.end(), 0LL) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}