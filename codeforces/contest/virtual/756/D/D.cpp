#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int root;
    vector<int> par(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        par[i] = x;
        adj[x].push_back(i);
        if (i == x)root = i;
    }

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];

    vector<int> dis(n + 1);
    dis[root] = 0;

    int last = 0;
    vector<int> ans(n + 1);
    unordered_set<int> s;
    s.insert(root);
    for (int i = 1; i <= n; i++) {
        int v = p[i];
        if (!s.count(v)) { cout << -1 << endl; return; }
        if (v != root) {
            dis[v] = ++last;
        }
        s.erase(v);
        for (auto& u : adj[v])s.insert(u);
    }

    for (int i = 1; i <= n; i++) {
        cout << dis[i] - dis[par[i]] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}