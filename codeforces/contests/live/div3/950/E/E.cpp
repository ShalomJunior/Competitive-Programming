#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e8;
uint64_t rng() {
    static mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<uint64_t> distribution(0, numeric_limits<uint64_t>::max());
    return distribution(generator);
}

void solve() {
    int n, m;
    cin >> n >> m;
    set<int> all;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            all.insert(a[i][j]);
        }
    }
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
            all.insert(b[i][j]);
        }
    }
    map<int, int> h;
    set<int> hs;
    for (auto& c : all) {
        int val;
        do {
            val = rng() % INF;
        } while (hs.count(val));
        h[c] = val;
        hs.insert(val);
    }
    auto get = [&](vector<vector<int>>& g) {
        set<int> r;
        for (int i = 0; i < n; i++) {
            int H = 0;
            for (int j = 0; j < m; j++) H ^= h[g[i][j]];
            r.insert(H);
        }
        set<int> c;
        for (int j = 0; j < m; j++) {
            int H = 0;
            for (int i = 0; i < n; i++) H ^= h[g[i][j]];
            c.insert(H);
        }
        return make_pair(r, c);
        };
    auto [r1, c1] = get(a);
    auto [r2, c2] = get(b);
    cout << (r1 == r2 && c1 == c2 ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
