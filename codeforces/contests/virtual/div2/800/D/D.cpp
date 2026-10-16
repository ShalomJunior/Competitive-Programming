#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);
    }
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
    int ans = 0;
    vector<bool> vis(n);
    vector<int> sum(n);
    function<void(int)> dfs = [&](int r) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                dfs(c);
            }
        }
        if (sum[r] < l[r]) ans++;
        };
    dfs(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}