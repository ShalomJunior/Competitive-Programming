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

int g(vector<int> a, vector<int> b) {
    int n = a.size();
    dsu ds(n);
    for (int i = 0; i < n; i++) ds.join(a[i], b[i]);
    set<int> r;
    for (int i = 0; i < n; i++) r.insert(ds.root(i));
    return n - r.size();
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        int k = i - p[i];
        if (k < 0) k += n;
        h[k]++;
    }
    vector<int> ans;
    for (auto& [k, v] : h) {
        if (v >= n - 2 * m) {
            vector<int> b(n);
            iota(b.begin() + k, b.end(), 0);
            iota(b.begin(), b.begin() + k, n - k);
            if (g(p, b) <= m) {
                ans.push_back(k);
            }
        }
    }
    cout << ans.size() << " ";
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}