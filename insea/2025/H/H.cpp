#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
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
    vector<int> a(N, -1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (a[x] == -1) {
            a[x] = i;
        }
        else if (x != 1) {
            ds.join(a[x], i);
        }
        else {}
    }
    vector<int> h(N, -1);
    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) {
            if (a[j] != -1) {
                if (h[i] == -1) {
                    h[i] = a[j];
                }
                else {
                    ds.join(h[i], a[j]);
                }
            }
        }
    }
    set<int> p;
    for (int i = 0; i < n; i++) p.insert(ds.root(i));
    cout << (p.size() > 1 ? "no" : "yes") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
