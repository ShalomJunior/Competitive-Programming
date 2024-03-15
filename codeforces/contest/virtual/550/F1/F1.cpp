#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int root, deg = 0;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() > deg) {
            root = i;
            deg = adj[i].size();
        }
    }
    queue <int> q;
    vector<bool> vis(n);
    function<void(int)> Bfs = [&](int r) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                cout << r + 1 << " " << c + 1 << endl;
                vis[c] = true;
                q.push(c);
            }
        }
        };
    q.push(root);
    while (!q.empty()) {
        Bfs(q.front());
        q.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}