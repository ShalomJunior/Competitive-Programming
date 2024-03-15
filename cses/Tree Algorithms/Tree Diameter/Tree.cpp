#include <bits/stdc++.h>

using namespace std;

int node, dis;
vector<bool> vis;
vector<vector<int>> adj;

void dfs(int r, int c) {
    vis[r] = true;
    for (auto& u : adj[r]) {
        if (vis[u])continue;
        dfs(u, c + 1);
    }
    if (c > dis) {
        dis = c;
        node = r;
    }
}

int main() {
    int n; cin >> n;
    vis.resize(n + 1);
    adj.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    node = 1; dis = 0;
    dfs(1, 0);
    vis = vector<bool>(n + 1);
    dis = 0;
    dfs(node, 0);
    cout << dis << endl;
}