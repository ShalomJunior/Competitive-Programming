#include <bits/stdc++.h>
using namespace std;

const int N = 2000;
bool dp[N][N];

void init() {

}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    x--;
    vector<bool> vis(n);
    vector<int> depth(n);
    vector<int> child(n, 1);
    function<void(int)> dfs = [&](int r) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                depth[c] = depth[r] + 1;
                dfs(c);
                child[r] += child[c];
            }
        }
        };
    dfs(0);
    int tot = 0;
    int should = 0;
    cout << (dp[tot][should] ? "Ashish" : "Ayush") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin >> t;
    while (t--) solve();
}
