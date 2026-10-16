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
    dsu ds(n);
    set<int> in;
    vector<pair<int, int>> all;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        --u;
        int cnt = 0;
        vector<int> to;
        for (auto it = in.begin(); it != in.end() && *it < u && (int)all.size() < n - 1; it++) {
            if (ds.root(u) != ds.root(*it)) {
                ds.join(u, *it);
                all.push_back({ u, *it });
                if (cnt > 0) {
                    to.push_back(*it);
                }
                cnt++;
            }
        }
        if (cnt == 0) in.insert(u);
        for (auto& c : to) in.erase(c);
    }
    int z = all.size();
    if (z == n - 1) {
        cout << "YES" << endl;
        for (auto& [u, v] : all) cout << u + 1 << " " << v + 1 << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
