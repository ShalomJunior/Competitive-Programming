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

    vector<bool> vis(n);
    vector<int> dis(n);
    queue<int> q;
    auto Bfs = [&](int r, int d) {
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                q.push(c);
                vis[c] = true;
                dis[c] = dis[r] + 1;
            }
        }
        };
    q.push(0);
    Bfs(0, 0);
    for (int i = 0; i < n; i++) {
        if (dis[i] % 2 == 0) {
            cout << i + 1 << " ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}