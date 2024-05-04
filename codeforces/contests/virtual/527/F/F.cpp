#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int tot = accumulate(a.begin(), a.end(), 0LL);
    vector<bool> vis(n);
    vector<int> depth(n);
    vector<int> cost(n);
    function<void(int)> dfs = [&](int r) {
        vis[r] = true;
        cost[r] = a[r];
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                depth[c] = depth[r] + 1;
                dfs(c);
                cost[r] += cost[c];
            }
        }
        };
    dfs(0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += depth[i] * a[i];
    }
    vector<int> dp(n);
    dp[0] = ans;
    function<void(int)> dfs2 = [&](int r) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                dp[c] = dp[r] - cost[c] + tot - cost[c];
                dfs2(c);
            }
        }
        };
    vis = vector<bool>(n);
    dfs2(0);
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}