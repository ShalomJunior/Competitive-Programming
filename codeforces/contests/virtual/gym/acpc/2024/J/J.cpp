#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int get(map<int, int>& h, map<int, int>& mp) {
    int tot = 0;
    for (auto& [k, v] : mp) {
        if (h[k] != v) return INF;
        tot += v;
    }
    return tot;
}

void solve() {
    int n;
    cin >> n;
    vector<int> g(n);
    map<int, int> h;
    for (auto& c : g) {
        cin >> c;
        c--;
        h[c]++;
    }
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> o, e;
    vector<bool> vis(n);
    function<void(int, int)> dfs = [&](int r, int x) {
        vis[r] = true;
        x & 1 ? o.push_back(r) : e.push_back(r);
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                dfs(c, x ^ 1);
            }
        }
        };
    dfs(0, 0);
    map<int, int> x;
    for (auto& c : o) x[g[c]]++;
    map<int, int> y;
    for (auto& c : e) y[g[c]]++;
    int ans = min(get(h, x), get(h, y));
    cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}