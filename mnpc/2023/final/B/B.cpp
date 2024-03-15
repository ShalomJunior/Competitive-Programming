#include <bits/stdc++.h>
#define int long long
using namespace std;

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

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    dsu ds(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        ds.join(a, b);
    }
    map<pair<int, int>, int> hash;
    int initial = 0;
    for (int i = 0; i < q; i++) {
        int a, b, v;
        cin >> a >> b >> v;
        --a, --b;
        a = ds.root(a);
        b = ds.root(b);
        if (a == b) {
            initial += v;
        }
        else {
            if (a > b) swap(a, b);
            hash[{a, b}] += v;
        }
    }
    int ans = initial;
    for (auto& [p, add] : hash) {
        ans = max(ans, initial + add);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}