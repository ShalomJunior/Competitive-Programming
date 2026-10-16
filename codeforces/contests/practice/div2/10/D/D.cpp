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

void solve() {
    int n;
    cin >> n;
    dsu ds(n);
    vector<pair<int, int>> r;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (ds.root(a) != ds.root(b)) {
            ds.join(a, b);
        }
        else {
            r.push_back({ a, b });
        }
    }
    set<int> roots;
    for (int i = 0; i < n; i++) roots.insert(ds.root(i));
    int x = roots.size() - 1;
    int y = r.size();
    assert(x == y);
    cout << x << endl;
    int j = 0;
    for (auto it = roots.begin(); it != roots.end(); it++) {
        if (it == roots.begin()) continue;
        cout << r[j].first + 1 << " " << r[j].second + 1 << " ";
        cout << *roots.begin() + 1 << " " << *it + 1 << endl;
        j++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}