#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5;
class dsu {
public:
    vector<int> parents;
    vector<int> sizes;
    dsu(int n) {
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
        sizes.resize(n, 1);
    }
    int root(int u) {
        return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v) {
        int a = root(u);
        int b = root(v);
        if (a == b) return 0;
        if (sizes[a] > sizes[b]) swap(a, b);
        parents[a] = b;
        sizes[b] += sizes[a];
        return 1;
    }
};

int helper(vector<int>& a) {
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += __gcd(a[i], a[j]);
        }
    }
    return ans;
}

int go(vector<int>& a) {
    int n = a.size();
    if (n < (int)3e3) return helper(a);
    vector<vector<int>> d(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            d[j].push_back(i);
        }
    }
    vector<int> cnt(N + 1);
    for (int i = 0; i < n; i++) {
        ++cnt[a[i]];
    }
    vector<int> dp(N + 1);
    for (int i = N; i >= 1; i--) {
        int s = 0;
        for (int j = i; j <= N; j += i) {
            s += cnt[j];
        }
        s = s * s - s >> 1ll;
        for (int j = i + i; j <= N; j += i) {
            s -= dp[j];
        }
        dp[i] = s;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += dp[i] * i;
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int>a(n);
    for (auto& c : a) cin >> c;
    dsu ds(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        ds.join(x, y);
    }
    map<int, vector<int>> hash;
    for (int i = 0; i < n; i++) {
        int r = ds.root(i);
        hash[r].push_back(a[i]);
    }
    int res = 0;
    for (auto& [k, vec] : hash) {
        res += go(vec);
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
