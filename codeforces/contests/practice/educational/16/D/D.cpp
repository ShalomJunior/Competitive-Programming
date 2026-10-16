#include <bits/stdc++.h>
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
    int n, m, k;
    cin >> n >> m >> k;
    char g[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    auto h = [&](int i, int j) {
        return i * m + j;
        };
    int N = n * m;
    dsu ds(N);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') {
                if (i && g[i - 1][j] == '.') ds.join(h(i - 1, j), h(i, j));
                if (j && g[i][j - 1] == '.') ds.join(h(i, j - 1), h(i, j));
            }
        }
    }
    map<int, set<pair<int, int>>> cnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') {
                if (i && g[i - 1][j] == '*') cnt[ds.root(h(i, j))].insert({ h(i, j), h(i - 1, j) });
                if (i + 1 < n && g[i + 1][j] == '*') cnt[ds.root(h(i, j))].insert({ h(i, j), h(i + 1, j) });
                if (j && g[i][j - 1] == '*') cnt[ds.root(h(i, j))].insert({ h(i, j), h(i, j - 1) });
                if (j + 1 < m && g[i][j + 1] == '*') cnt[ds.root(h(i, j))].insert({ h(i, j), h(i, j + 1) });
            }
        }
    }
    while (k--) {
        int i, j;
        cin >> i >> j;
        --i, --j;
        cout << cnt[ds.root(h(i, j))].size() << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
