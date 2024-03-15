#include <bits/stdc++.h>

using namespace std;

int mx;
vector<vector<int>> adj;
vector<int> bloc, vis;
set<int> connect;

void res(int n) {
    mx = 1;
    adj.resize(n + 1);
    bloc.resize(n + 1);
    vis.resize(n + 1);
}

void dfs(int u, bool head) {
    vis[u] = true;
    //cout << "adding top = " << u << endl;
    connect.insert(u);
    for (auto& c : adj[u]) {
        if (head) {
            mx = max(mx, (int)connect.size());
            connect.clear();
            connect.insert(u);
        }
        if (!vis[c]) {
            if (bloc[c]) {
                if (!head)connect.insert(c);
            }
            else {
                dfs(c, false);
            }
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    res(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool trie = false;
    for (int i = 1; i <= n; i++) {
        cin >> bloc[i];
        trie |= bloc[i];
    }

    if (!trie) {
        cout << n << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (bloc[i]) {
            //cout << "starting " << i << endl;
            dfs(i, true);
            mx = max(mx, (int)connect.size());
            vis[i] = false;
            vis.clear();
            connect.clear();
        }
    }
    cout << mx << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}