#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<Mine> vec(m);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        vec[i].F = a, vec[i].S = b;
    }
    vector<int> dis(n);
    vector<bool> vis(n);
    queue<int> q;
    function<bool(int)> Bfs = [&](int r) {
        bool ans = true;
        for (auto& c : adj[r]) {
            if (vis[c]) {
                if (dis[c] != (dis[r] + 1) % 2) {
                    return false;
                }
            }
            else {
                dis[c] = (dis[r] + 1) % 2;
                q.push(c);
                vis[c] = true;
            }
        }
        return ans;
        };
    q.push(0);
    int i = 0;
    while (!q.empty()) {
        bool b = Bfs(q.front());
        if (!b) {
            cout << "NO" << endl;
            return;
        }
        q.pop();
        i++;
    }
    cout << "YES" << endl;
    for (int i = 0; i < m; i++) {
        cout << dis[vec[i].F];
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}