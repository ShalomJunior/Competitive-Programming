#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
bitset<N> prime;
int f[N];
vector<vector<int>> adj;
vector<int> db;

int binp(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) { ans = (ans * a) % MOD; }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

int inv(int n) { return binp(n, MOD - 2); }

void prepare() {
    for (int i = 2; i < N; i++)prime.set(i);
    for (int i = 2; i < N; i++) {
        if (!prime[i])continue;
        for (int j = i * i; j < N; j++)prime.reset(i);
    }

    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = (f[i - 1] * i) % MOD;
}

int dfs(int v, int p) {
    int ans = 1;
    for (auto& u : adj[v]) {
        if (u != p) {
            ans = (ans * dfs(u, v)) % MOD;
        }
    }
    ans = (ans * f[adj[v].size() - 1]) % MOD;
    db[v] = ans;
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int n; cin >> n;
    adj.resize(n + 1);
    db.resize(n + 1);
    unordered_map<int, int> p;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        p[b] = a;
    }

    int root;
    for (int i = 1; i < n; i++) {
        if (!p.count(i))root = i;
    }
    dfs(root, -1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == root)ans = (ans + db[root]) % MOD;
        else {
            int add = (db[p[i]] * adj[i].size()) % MOD;
            add = (add * inv(adj[p[i]].size())) % MOD;
            ans = (ans + add) % MOD;
        }
    }
    ans = (ans * inv(n)) % MOD;
    cout << ans << endl;
}