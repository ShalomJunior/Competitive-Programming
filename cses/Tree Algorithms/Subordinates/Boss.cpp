#include <bits/stdc++.h>

using namespace std;

vector<bool> vis;
vector<vector<int>> adj;
vector<int> sub;

int dfs(int r) {
    vis[r] = true;
    for (auto u : adj[r]) {
        if (vis[u])continue;
        sub[r] += dfs(u);
    }
    return 1 + sub[r];
}

int main() {
    int n; cin >> n;
    vis.resize(n + 1); sub.resize(n + 1);
    adj.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        int a; cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << sub[i] << " ";
    }
    cout << endl;
}