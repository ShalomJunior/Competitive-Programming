#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;
int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ok = true;
    map<int, int> D;
    vector<bool> vis(n);
    vector<int> id(n);
    function<void(int, int)> dfs = [&](int r, int d) {
        vis[r] = true;
        D[d]++;
        for (auto& c : adj[r]) {
            if (vis[c]) {
                if ((id[c] - id[r]) % 2 == 0) ok = false;
            }
            else {
                id[c] = id[r] + 1;
                dfs(c, d + 1);
            }
        }
        };
    int ans = 1;
    for (int u = 0; u < n; u++) {
        if (!vis[u]) {
            D.clear();
            dfs(u, 0);
            int x = 1;
            for (int i = 0; D.find(i) != D.end(); i += 2) {
                x *= power(2, D[i]);
                x %= MOD;
            }
            int y = 1;
            for (int i = 1; D.find(i) != D.end(); i += 2) {
                y *= power(2, D[i]);
                y %= MOD;
            }
            int z = x + y;
            z %= MOD;
            ans *= z;
            ans %= MOD;
        }
    }
    cout << (ok ? ans % MOD : 0) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
