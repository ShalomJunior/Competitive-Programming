#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n; cin >> n;
    vector<int> d(n);
    for (auto& c : d) cin >> c;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(n);
    vector<int> leaves(n);
    int temp = 0;
    function<void(int, int)> dfs = [&](int r, int cost) {
        vis[r] = true;
        cost += d[r];
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                dfs(c, cost);
                leaves[r] += leaves[c];
            }
        }
        if (leaves[r] == 0) {
            temp += cost;
            leaves[r] = 1;
        }
        };
    dfs(0, 0);
    int ans = temp;
    for (int i = 0; i < n; i++) {
        ans = max(ans, temp - d[i] * leaves[i]);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
