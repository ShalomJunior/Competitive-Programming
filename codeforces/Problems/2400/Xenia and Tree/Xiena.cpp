#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> dis;
vector<bool> red;
vector<vector<int>> adj;


void dfs(int v, int cnt) {
    if (cnt >= dis[v] && v != 1)
        return;
    red[v] = true;
    for (auto& r : adj[v]) {
        if (red[r])continue;
        dfs(r, cnt + 1);
    }
    dis[v] = cnt;
    red[v] = false;
}

int main() {
    cin >> n >> m;

    red.resize(n + 1);
    dis.resize(n + 1, INT_MAX);
    adj.resize(n + 1);

    red[1] = true; dis[1] = 0;

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    while (m--) {
        int t, v; cin >> t >> v;
        if (t == 1)
            dfs(v, 0), red[v] = true;
        else
            cout << dis[v] << endl;
    }
}