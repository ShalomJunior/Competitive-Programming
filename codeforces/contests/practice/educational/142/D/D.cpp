#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e15;
uint64_t rng() {
    static mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<uint64_t> distribution(0, numeric_limits<uint64_t>::max());
    return distribution(generator);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    map<vector<int>, vector<int>> match;
    for (int i = 0; i < n; i++) match[a[i]].push_back(i);
    vector<vector<int>> g;
    for (auto& [k, v] : match) g.push_back(k);
    int z = g.size();
    vector<int> ans(z);
    auto go = [](vector<vector<int>> v, int n, int m, vector<int>& ans, bool reverse) {
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            b[i] = rng() % MOD;
        }
        vector<map<int, vector<int>>> h(m);
        for (int k = 0; k < n; k++) {
            int i = reverse ? n - 1 - k : k;
            vector<int> p(m);
            for (int j = 0, hash = 0; j < m; j++) {
                int x = v[i][j] - 1;
                p[x] = j;
                hash = (hash + x * b[j]) % MOD;
                h[j][hash].push_back(i);
            }
            for (int j = 0, hash = 0; j < m; j++) {
                hash = (hash + p[j] * b[j]) % MOD;
                if (h[j].count(hash)) {
                    for (auto& z : h[j][hash])
                        ans[z] = max(ans[z], j + 1);
                }
            }
        }
        };
    go(g, z, m, ans, false);
    go(g, z, m, ans, true);
    vector<int> res(n);
    for (int i = 0; i < z; i++) {
        for (auto& j : match[g[i]]) {
            res[j] = ans[i];
        }
    }
    for (auto& c : res) cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}