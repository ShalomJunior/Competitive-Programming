#include <bits/stdc++.h>
using namespace std;

class dsu {
public:
    vector<int> parents;
    vector<int> sizes;
    vector<int> state;
    dsu(int n) {
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
        sizes.resize(n, 1);
        state.resize(n);
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
        if (state[a] == -1 || state[b] == -1) {
            state[a] = state[b] = -1;
        }
        else if (state[a] == 1 || state[b] == 1) {
            state[a] = state[b] = 1;
        }
        else {}
        return 1;
    }
};

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u = i + 2;
        int v; cin >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    string s; cin >> s;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        if (s[i] == 'S' || s[j] == 'S') return s[i] == 'S';
        if (s[i] == 'C' || s[j] == 'C') return s[i] == 'C';
        return true;
        });
    dsu ds(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') ds.state[i] = 1;
        if (s[i] == 'S') ds.state[i] = -1;
    }
    vector<bool> vis(n);
    bool flag = true;
    for (int i = 0; i < n; i++) {
        int u = p[i];
        if (s[u] == 'P') flag = false;
        for (auto& v : adj[u]) {
            int ru = ds.root(u);
            int rv = ds.root(v);
            int x = ds.state[ru];
            int y = ds.state[rv];
            if (flag) {
                if ((x == y) || (x != 1 && y != 1)) {
                    ds.join(u, v);
                }
            }
            else {
                if (x == y || x == 0 || y == 0) ds.join(u, v);
            }
        }
        vis[u] = true;
    }
    set<int> roots;
    for (int i = 0; i < n; i++)roots.insert(ds.root(i));
    cout << roots.size() - 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}