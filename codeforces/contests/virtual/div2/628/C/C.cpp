#include <bits/stdc++.h>
#define Mine pair<int, int>
#define F first
#define S second
using namespace std;

auto bfs(vector<vector<int>>& adj, int r, vector<int>& par) {
    int n = adj.size();
    vector<int> dis(n);
    vector<bool> vis(n);
    queue<int> q;
    q.push(r); vis[r] = true;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto& c : adj[v]) {
            if (!vis[c]) {
                vis[c] = true;
                dis[c] = dis[v] + 1;
                par[c] = v;
                q.push(c);
            }
        }
    }
    int d = *max_element(dis.begin(), dis.end());
    int far;
    for (int i = 0; i < n; i++) {
        if (dis[i] == d) {
            far = i;
            break;
        }
    }
    return make_pair(far, par[far]);
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    vector<pair<int, int>> edges(n);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        edges[i].F = min(a, b);
        edges[i].S = max(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> par(n);
    auto f = bfs(adj, 0, par);
    auto g = bfs(adj, f.F, par);
    int x = g.F;
    set<Mine> ban;
    while (x != f.F) {
        ban.insert({ min(x, par[x]), max(x, par[x]) });
        x = par[x];
    }
    if (f.F > f.S) swap(f.F, f.S);
    if (g.F > g.S) swap(g.F, g.S);
    set<int> s;
    for (int i = 2; i < n - 1; i++) s.insert(i);
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (edges[i] == f) {
            cout << 0 << " ";
        }
        else if (edges[i] == g) {
            cout << 1 << " ";
        }
        else {
            if (*s.begin() != 2 || ban.size() == n - 1 || !ban.count(edges[i])) {
                cout << *s.begin() << " ";
                s.erase(s.begin());
            }
            else {
                cout << *next(s.begin()) << " ";
                s.erase(next(s.begin()));
            }
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}