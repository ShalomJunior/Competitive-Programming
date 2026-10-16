#include <bits/stdc++.h>
using namespace std;

const int N = 10;
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
    int n, m;
    cin >> n >> m;
    vector<map<int, int>> h(N + 1);
    for (int i = 0; i < m; i++) {
        int a, d, k;
        cin >> a >> d >> k;
        h[d][a] = max(h[d][a], k);
    }
    vector<map<int, vector<int>>> a(N + 1);
    for (int j = 1; j <= N; j++) {
        auto& mp = a[j];
        for (int i = 0; i < n; i++) {
            if (i < j) mp[i].resize(n / j + 2);
            if (h[j][i]) {
                mp[i % j][i / j] = i + h[j][i] * j;
            }
            if (i / j) {
                mp[i % j][i / j] = max(mp[i % j][i / j], mp[i % j][i / j - 1]);
            }
        }
    }
    dsu ds(n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = j; k <= N && i + k <= n; k += j) {
                if (a[j][i % j][i / j] >= i + k) {
                    ds.join(i, i + k);
                }
            }
        }
    }
    set<int> r;
    for (int i = 1; i <= n; i++) r.insert(ds.root(i));
    cout << r.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
