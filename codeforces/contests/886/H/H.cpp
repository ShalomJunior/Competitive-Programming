#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    bool bad = false;
    vector<vector<int>> adj(n);
    map<pair<int, int>, int> h;
    for (int i = 0; i < m; i++) {
        int a, b, d; cin >> a >> b >> d;
        --a, --b;
        if (h.count({ a, b }) && h[{a, b}] != -d) {
            bad = true;
        }
        adj[a].push_back(b);
        adj[b].push_back(a);
        h[{a, b}] = -d;
        h[{b, a}] = d;
    }
    if (bad) { cout << "NO" << endl; return; }
    vector<bool> vis(n);
    vector<long long> dis(n);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        queue<int> q;
        q.push(i); vis[i] = 0;
        while (!q.empty()) {
            int r = q.front(); q.pop();
            for (auto& c : adj[r]) {
                if (vis[c]) {
                    if (dis[c] != dis[r] + h[{r, c}]) {
                        cout << "NO" << endl;
                        return;
                    }
                }
                else {
                    dis[c] = dis[r] + h[{r, c}];
                    q.push(c);
                    vis[c] = true;
                }
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}