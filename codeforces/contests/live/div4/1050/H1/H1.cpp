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
        set<int> r;
        for (int j = 0; j < m; j++) {
            for (auto di : { -1, 1 }) {
                int ni = i + di;
                if (0 <= ni && ni < n && !g[i][j]) {
                    if (g[ni][j]) {
                        r.insert(ds.root(h(ni, j)));
                    }
                }
            }
            r.insert(ds.root(h(i, j)));
        }
        int cnt = 0;
        for (auto& c : r) cnt += ds.sizes[c];
        ans = max(ans, cnt);
    }
    for (int j = 0; j < m; j++) {
        set<int> r;
        for (int i = 0; i < n; i++) {
            for (auto dj : { -1, 1 }) {
                int nj = j + dj;
                if (0 <= nj && nj < m) {
                    if (g[i][nj]) {
                        r.insert(ds.root(h(i, nj)));
                    }
                }
            }
            r.insert(ds.root(h(i, j)));
        }
        int cnt = 0;
        for (auto& c : r) cnt += ds.sizes[c];
        ans = max(ans, cnt);
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
    auto bfs = [&](map<int, vector<int>> adj) {
        map<int, bool> vis;
        set<int> s;
        function<void(int)> dfs = [&](int r) {
            //cerr << r << " ";
            vis[r] = true;
            s.insert(ds.root(r));
            for (auto& c : adj[r]) {
                if (!vis[c]) {
                    dfs(c);
                }
            }
            };
        //cerr << endl;
        for (auto& [r, vec] : adj) {
            if (!vis[r]) {
                s.clear();
                dfs(r);
                int tot = 0;
                for (auto& c : s) tot += ds.sizes[c];
                ans = max(ans, tot);
                //cerr << "tot = " << tot << endl;
            }
        }
        };
    for (int i = 0; i < n; i++) {
        map<int, vector<int>> adj;
        for (int j = 0; j < m; j++) {
            for (auto di : { -1, 1 }) {
                int ni = i + di;
                if (0 <= ni && ni < n && !g[i][j]) {
                    if (g[ni][j]) {
                        adj[h(ni, j)].push_back(h(i, j));
                        adj[h(i, j)].push_back(h(ni, j));
                    }
                }
            }
            if (j + 1 >= m) continue;
            if (ds.root(h(i, j)) != ds.root(h(i, j + 1))) {
                adj[h(i, j)].push_back(h(i, j + 1));
                adj[h(i, j + 1)].push_back(h(i, j));
            }
        }
        bfs(adj);
        //cerr << endl;
    }
    for (int j = 0; j < m; j++) {
        map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            for (auto dj : { -1, 1 }) {
                int nj = j + dj;
                if (0 <= nj && nj < m && !g[i][j]) {
                    if (g[i][nj]) {
                        adj[h(i, nj)].push_back(h(i, j));
                        adj[h(i, j)].push_back(h(i, nj));
                    }
                }
            }
            if (i + 1 >= n) continue;
            if (ds.root(h(i, j)) != ds.root(h(i + 1, j))) {
                adj[h(i, j)].push_back(h(i + 1, j));
                adj[h(i + 1, j)].push_back(h(i, j));
            }
        }
        bfs(adj);
    }
    cerr << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
*/