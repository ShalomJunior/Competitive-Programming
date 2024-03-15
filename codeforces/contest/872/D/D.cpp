#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e6;

int binp(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) { ans = (ans * a) % MOD; }
        b >>= 1;
        a = (a * a) % MOD;
    }
    return ans;
}

int inv(int n) { return binp(n, MOD - 2); }

int f[N], inv_f[N];
void prepare() {
    inv_f[0] = f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = (f[i - 1] * i) % MOD;
        inv_f[i] = inv(f[i]);
    }
}

int root, dp;
vector<bool> vis;
vector<int> dis;
vector<vector<int>> adj;
void dfs(int v, int p, int cnt) {
    if (cnt > dp) { dp = cnt; root = v; }
    for (auto& u : adj[v]) {
        if (u != p)dfs(u, v, cnt + 1);
    }
}

void bfs(int root) {
    queue<int> q; q.push(root);
    vis[root] = true; dis[root] = 0;
    while (!q.empty()) {
        int r = q.front(); q.pop();
        for (auto& u : adj[r]) {
            if (vis[u]) continue;
            vis[u] = true;
            dis[u] = dis[r] + 1;
            q.push(u);
        }
    }
}

void solve() {
    int n, k; cin >> n >> k;

    adj.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (k & 1) { cout << 1 << endl; return; }

    dp = 0; dfs(1, -1, 1);
    dp = 0; dfs(root, -1, 1);

    vis.resize(n + 1); dis.resize(n + 1);
    bfs(root);
    int M = 0;
    set<pair<int, int>> s;
    for (int i = 1; i <= n; i++) {
        M = max(M, dis[i]);
        s.insert({ -dis[i], i });
    }
    int all = 0;
    unordered_multiset<int> um;
    for (int i = 1; i <= n; i++) {
        all += (M - dis[i]) + 1;
        um.insert(dis[i]);
    }

    int ans = 0;
    for (auto it = s.begin(); it != s.end(); it++) {
        ans = (ans + all) % MOD;
    }
    for (int i = M - 1; i > 0; i--) {
        int cnt = um.count(i);
        cout << "i = " << i << endl;
        all -= (int)um.size();
        um.erase(i);
        ans = (ans + cnt * all) % MOD;
    }

    ans = (ans * f[k]) % MOD;
    ans = (ans * f[n - k]) % MOD;
    ans = (ans * inv_f[n]) % MOD;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    solve();
}