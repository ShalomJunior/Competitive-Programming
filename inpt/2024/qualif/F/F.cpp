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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    dsu ds(n);
    for (int i = 0; i < n; i++) {
        ds.join(i, a[i] - 1);
    }
    set<int> p;
    for (int i = 0; i < n; i++) {
        p.insert(ds.root(i));
    }
    cout << p.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}




