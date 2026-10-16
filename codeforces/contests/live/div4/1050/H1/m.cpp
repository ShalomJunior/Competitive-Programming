#include <bits/stdc++.h>
using namespace std;

class dsu {
public:
    vector<int> parents;
    vector<int> sizes;
    stack<tuple<int, int, int>> history;

    dsu(int n) {
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
        sizes.resize(n, 1);
    }

    int root(int u) {
        if (parents[u] != u) {
            int original_parent = parents[u];
            int root_u = root(parents[u]);
            history.push({ u, original_parent, sizes[original_parent] });
            parents[u] = root_u;
        }
        return parents[u];
    }

    bool join(int u, int v) {
        int a = root(u);
        int b = root(v);
        if (a == b) return false;
        if (sizes[a] > sizes[b]) swap(a, b);
        history.push({ a, parents[a], sizes[b] });
        parents[a] = b;
        sizes[b] += sizes[a];
        return true;
    }

    bool rollback() {
        if (history.empty()) return false;
        auto [a, oldParent, oldSize] = history.top();
        history.pop();
        sizes[parents[a]] = oldSize;
        parents[a] = oldParent;
        return true;
    }
};


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            g[i][j] = c == '#' ? 1 : 0;
        }
    }
    auto h = [&](int i, int j) {
        return i * m + j;
        };
    int N = n * m;
    dsu ds(N);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j]) {
                if (i && g[i - 1][j]) ds.join(h(i - 1, j), h(i, j));
                if (j && g[i][j - 1]) ds.join(h(i, j - 1), h(i, j));
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) ans = max(ans, ds.sizes[i]);
    for (int i = 0; i < n; i++) {
        int state = ds.history.size();
        for (int j = 0; j < m; j++) {
            for (auto di : { -1, 1 }) {
                int ni = i + di;
                if (0 <= ni && ni < n) {
                    if (g[ni][j]) {
                        ds.join(h(i, j), h(ni, j));
                    }
                }
            }
            if (j + 1 < m) {
                ds.join(h(i, j), h(i, j + 1));
            }
        }
        for (int i = 0; i < N; i++) ans = max(ans, ds.sizes[i]);
        while (ds.history.size() > state) ds.rollback();
    }
    for (int j = 0; j < m; j++) {
        int state = ds.history.size();
        for (int i = 0; i < n; i++) {
            for (auto dj : { -1, 1 }) {
                int nj = j + dj;
                if (0 <= nj && nj < m) {
                    if (g[i][nj]) {
                        ds.join(h(i, j), h(i, nj));
                    }
                }
            }
            if (i + 1 < n) {
                ds.join(h(i, j), h(i + 1, j));
            }
        }
        for (int i = 0; i < N; i++) ans = max(ans, ds.sizes[i]);
        while (ds.history.size() > state) ds.rollback();
    }
    assert(ans <= N);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}


/*
void dbg(dsu ds) {
    for (auto& c : ds.parents) cerr << c << " ";
    cerr << endl;
    for (auto& c : ds.sizes) cerr << c << " ";
    cerr << endl;
}
*/