#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    --x, --y;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ch(n);
    vector<bool> vis(n), bad(n);
    bad[y] = true;
    function<void(int)> dfs = [&](int r) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                dfs(c);
                bad[r] = bad[r] | bad[c];
                ch[r] += 1 + ch[c];
            }
        }
        };
    dfs(x);
    long long ans = 1LL * n * (n - 1);
    int k = 1, l = 1 + ch[y];
    for (auto& c : adj[x]) {
        if (!bad[c]) k += 1 + ch[c];
    }
    ans -= 1LL * k * l;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
