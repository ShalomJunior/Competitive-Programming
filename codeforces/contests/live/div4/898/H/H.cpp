#include <bits/stdc++.h>
using namespace std;

set<int> get_cycle(vector<vector<int>>& adj) {
    int x, n = adj.size();
    set<int> ans;
    vector<int> vis(n), parent(n);
    function<bool(int, int)> dfs = [&](int r, int p) {
        vis[r] = true;
        parent[r] = p;
        for (auto c : adj[r]) {
            if (c == p) continue;
            else if (vis[c]) {
                x = r;
                ans.insert(c);
                return true;
            }
            else {
                if (dfs(c, r)) return true;
            }
        }
        return false;
        };
    dfs(0, 0);
    do {
        ans.insert(x);
        x = parent[x];
    } while (!ans.count(x));
    return ans;
}

void solve() {
    int n, a, b; cin >> n >> a >> b;
    --a, --b;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if (a == b) { cout << "NO" << endl; return; }
    auto cycle = get_cycle(adj);
    vector<int> da(n), db(n);
    queue<int> q;
    auto bfs = [&](int r, vector<int>& dis) {
        vector<bool> vis(n);
        queue<int> q;
        q.push(r);
        dis[r] = 0;
        vis[r] = true;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (auto& c : adj[x]) {
                if (vis[c]) continue;
                q.push(c);
                dis[c] = dis[x] + 1;
                vis[c] = true;
            }
        }
        };
    bfs(a, da); bfs(b, db);
    int in = -1;
    for (int i = 0; i < n; i++) {
        if (cycle.count(i)) {
            if (in == -1) in = i;
            else if (db[i] < db[in]) in = i;
        }
    }
    cout << (!db[in] || db[in] < da[in] ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}