#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> o, e;
    vector<bool> vis(n);
    function<void(int, int)> dfs = [&](int r, int d) {
        vis[r] = true;
        d & 1 ? o.push_back(r) : e.push_back(r);
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                dfs(c, d + 1);
            }
        }
        };
    dfs(0, 0);
    if (o.size() <= n / 2) {
        cout << o.size() << endl;
        for (auto& c : o) cout << c + 1 << " ";
    }
    else {
        cout << e.size() << endl;
        for (auto& c : e) cout << c + 1 << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}