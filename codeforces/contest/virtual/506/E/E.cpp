#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> dis(n), par(n);
    vector<bool> vis(n);
    set<int> leaves;
    function<void(int)> dfs = [&](int r) {
        vis[r] = true;
        int down = 0;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                par[c] = r;
                dis[c] = dis[r] + 1;
                dfs(c);
                down++;
            }
        }
        if (!down) leaves.insert(r);
        };
    dfs(0);
    int D = *max_element(dis.begin(), dis.end());
    for (int i = 0; i < n; i++) {

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}