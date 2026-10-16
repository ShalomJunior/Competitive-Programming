#include<bits/stdc++.h>
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

int g(vector<int>& p) {
    int n = p.size();
    dsu ds(n);
    for (int i = 0; i < n; i++) ds.join(i, p[i]);
    set<int> r;
    for (int i = 0; i < n; i++) r.insert(ds.root(i));
    return r.size();
}

void solve() {
    int n;
    cin >> n;
    dsu ds(n);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        ds.join(i, p[i]);
    }
    int m;
    cin >> m;
    vector<int> o;
    int z = n - g(p);
    for (int i = 0; i < n && z > m; i++) {
        int id = 0;
        vector<int> pos(n, -1);
        for (int j = p[i]; j != i; j = p[j]) pos[j] = id++;
        pos[i] = id;
        id = 0;
        for (int j = i + 1; j < n && z > m; j++) {
            if (pos[j] >= id) {
                o.push_back(i);
                o.push_back(j);
                z--;
                id = pos[j] + 1;
                swap(p[i], p[j]);
            }
        }
    }
    for (int i = 1; i < n && z < m; i++) {
        if (ds.root(0) != ds.root(i)) {
            o.push_back(0);
            o.push_back(i);
            ds.join(0, i);
            z++;
        }
    }
    cout << o.size() / 2 << endl;
    for (auto& c : o) cout << c + 1 << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
