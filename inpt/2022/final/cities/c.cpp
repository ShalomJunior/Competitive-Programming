#include <bits/stdc++.h>

using namespace std;

vector<int> vis, bc, ans;
vector<vector<int>> adj;

void res(int n) {
    vis.resize(n + 1);
    bc.resize(n + 1);
    ans.resize(n + 1);
    adj.resize(n + 1);
}

void dfs(int r, int cnt) {
    vis[r] = true;
    if (bc[r]) {
        ans[r] = 1;
        return;
    }
    for (auto c : adj[r]) {
        if (vis[c]) {

        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    res(n);
    for (int i = 0; i < m;i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n;i++) {
        cin >> bc[i + 1];
    }

    dfs(1, 1);
    int cnt = 0;
    for (auto& b : vis) {
        if (b) cnt++;
    }
    cout << cnt << endl;
}