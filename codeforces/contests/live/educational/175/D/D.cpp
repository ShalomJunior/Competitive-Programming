#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;
void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
        adj[p[i]].push_back(i);
    }
    vector<int> dp(n + 1);
    vector<int> dis(n + 1);
    vector<int> S(n + 1);
    vector<int> child(n + 1);
    function<void(int)> dfs = [&](int r) {
        for (auto& c : adj[r]) {
            dis[c] = dis[r] + 1;
            dfs(c);
        }
        };
    dfs(0);
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](const int& i, const int& j) {
        return dis[i] > dis[j];
        });
    for (int i = 0; i < n - 1; i++) {
        int u = o[i];
        int r = p[u];
        dp[u] = 1 + S[dis[u] + 1] - child[u];
        S[dis[u]] += dp[u] % MOD;
        child[r] += dp[u] % MOD;
    }
    cout << (child[0] + 1) % MOD << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
