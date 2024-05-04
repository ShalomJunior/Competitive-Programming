#include <bits/stdc++.h>
#define int long long
using namespace std;

const int P = 1e6 + 5;
const int MOD = 998244353;
const int N = 4050;

bitset<P> prime;
int f[N];
int inv_f[N];
int dp[N][N];

unordered_map<int, int> cnt;
vector<int> p;

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

void prepare() {
    for (int i = 2; i < P; i++)prime.set(i);
    for (int i = 2; i < P; i++) {
        if (!prime[i])continue;
        for (int j = i * i; j < P; j += i)prime.reset(j);
    }

    inv_f[0] = f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = (f[i - 1] * i) % MOD;
        inv_f[i] = inv(f[i]);
    }
}

int g(int x, int y) {
    int ans = dp[x][y];
    if (ans >= 0)return ans;

    if (x == p.size()) return (int)(y == 0);

    ans = (inv_f[cnt[p[x]]] * g(x + 1, y)) % MOD;

    if (y) ans = (ans + inv_f[cnt[p[x]] - 1] * g(x + 1, y - 1)) % MOD;

    dp[x][y] = ans;
    return ans;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        int a; cin >> a;
        cnt[a]++;
    }

    int ans = f[n];
    for (auto& [k, v] : cnt) {
        if (prime[k]) p.push_back(k);
        else ans = (ans * inv_f[v]) % MOD;
    }

    if (p.size() < n) { cout << 0 << endl; return; }

    sort(p.begin(), p.end());
    memset(dp, -1, sizeof(dp));
    ans = (ans * g(0, n)) % MOD;

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    solve();
}