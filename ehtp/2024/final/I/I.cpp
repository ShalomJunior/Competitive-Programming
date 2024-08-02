#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
    }
    for (auto& vec : adj) {
        sort(vec.begin(), vec.end());
        vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    }
    auto go = [&](int start, int end) {
        bool ans = false;
        vector<bool> vis(n);
        function<void(int, bool)> dfs = [&](int r, bool flag) {
            if (!flag && r == end) ans = true;
            if (!flag) vis[r] = true;
            for (auto& c : adj[r]) {
                if (!vis[c]) {
                    dfs(c, false);
                }
            }
            };
        dfs(start, true);
        return ans;
        };
    while (q--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        cout << (go(u, v) ? "YES" : "NO") << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}