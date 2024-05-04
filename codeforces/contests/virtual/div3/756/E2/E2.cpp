#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> x(k);
    for (int i = 0; i < k; i++) {
        cin >> x[i];
        --x[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n);
    vector<int> p(n);
    vector<int> time(n);
    vector<int> leaves(n, 1);
    function<void(int)> dfs = [&](int r) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                p[c] = r;
                time[c] = time[r] + 1;
                dfs(c);
                leaves[r] += leaves[c];
            }
        }
        };
    dfs(0);
    sort(x.begin(), x.end(), [&](int i, int j) {
        return time[i] < time[j];
        });
    vector<int> friends(n, INF);
    for (int i = 0; i < k; i++) {
        int u = x[i];
        int t = 0;
        while (p[u] != u && friends[u] > t) {
            friends[u] = t;
            u = p[u];
            t++;
        }
    }
    bool ans = false;
    vector<bool> bads(n);
    for (int i = 0; i < n; i++) {
        if (leaves[i] > 1)continue;
        int u = i;
        bool flag = true;
        while (true) {
            bool stop = bads[u];
            if (friends[u] <= time[u]) {
                bads[u] = true;
                flag = false;
                if (stop)break;
            }
            if (u == p[u])break;
            u = p[u];
        }
        ans |= flag;
    }
    if (ans) {
        cout << -1 << endl;
        return;
    }
    int res = 0;
    vis = vector<bool>(n);
    auto bfs = [&](int r) {
        queue<int> q;
        q.push(r);
        vis[r] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            vis[x] = true;
            if (bads[x]) {
                res++;
                continue;
            }
            for (auto& c : adj[x]) {
                if (!vis[c])q.push(c);
            }
        }
        };
    bfs(0);
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}