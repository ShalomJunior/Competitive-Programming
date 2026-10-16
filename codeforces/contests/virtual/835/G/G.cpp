#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    --a;
    --b;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }
    set<int> A, B;
    vector<bool> vis(n);
    auto S = &A;
    function<void(int, int)> dfs = [&](int r, int x) {
        vis[r] = true;
        if (x || (r != a && r != b)) S->insert(x);
        for (auto& [c, w] : adj[r]) {
            if (!vis[c] && c != b) {
                dfs(c, x ^ w);
            }
        }
        };
    dfs(a, 0);
    S = &B;
    vis = vector<bool>(n);
    dfs(b, 0);
    A.insert(0);
    for (auto& c : A) {
        if (B.count(c)) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}