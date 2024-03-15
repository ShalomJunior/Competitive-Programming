#include <bits/stdc++.h>

using namespace std;

int node, dis;
vector<int> ans;
vector<bool> vis, in;
vector<vector<int>> adj;


void res(int n) {
    vis.resize(n); in.resize(n);
    ans.resize(n); adj.resize(n);
}

void dfs(int r, int c) {
    vis[r] = true;
    for (auto& u : adj[r]) {
        if (!vis[u]) { dfs(u, c + 1); }
    }
    if (c > dis) { dis = c; node = r; }
}

void dfs3(int top, int r, int p, int c) {
    in[r] = true;
    for (auto u : adj[r]) {
        if (!in[u] && u != p) {
            dfs3(top, u, r, c + 1);
        }
    }
    ans[r] = top + c;
}

bool dfs2(int r, int p, int c) {
    vis[r] = true;

    if (c == dis) {
        in[r] = true;
        ans[r] = max(dis - c, c);
        return true;
    }

    for (auto& u : adj[r]) {
        if (vis[u])continue;
        bool b = dfs2(u, r, c + 1);
        if (b) {
            in[r] = true;
            ans[r] = max(dis - c, c);
            break;
        }
    }
    if (in[r]) {
        dfs3(ans[r], r, p, 0);
    }
    return in[r];
}


int main() {
    int n; cin >> n;
    res(n + 1);
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

    vis = vector<bool>(n + 1);
    dfs2(node, -1, 0);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}