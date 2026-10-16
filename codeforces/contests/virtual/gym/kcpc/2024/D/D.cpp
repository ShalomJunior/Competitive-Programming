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

template<typename T>
const T GCD(const T& a, const T& b) {
    return __gcd(a, b);
}

template<typename T, const T(*op)(const T&, const T&)>
class sparseTable {
public:
    vector<vector<T>> st;
    sparseTable(vector<T> vals) {
        int n = vals.size();
        int rows = __lg(n) + 1;
        st.resize(rows);
        st[0] = vals;
        for (int j = 1; j < rows; j++) {
            st[j].resize(n);
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[j][i] = op(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    T query(int l, int r) {
        int j = __lg(r - l + 1);
        return op(st[j][l], st[j][r - (1 << j) + 1]);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    set<int> all;
    for (int i = 0; i < n; i++) all.insert(i);
    sparseTable<int, GCD> g(a);
    dsu ds(n);
    for (int i = 0; i < n; i++) {
        int L = i, R = n - 1;
        while (L < R) {
            int mid = (L + R) / 2;
            if (g.query(i, mid) == a[i]) {
                if (L == mid) g.query(i, R) == a[i] ? L = R : R = L;
                else L = mid;
            }
            else  R = mid - 1;
        }
        while (!all.empty()) {
            auto it = all.lower_bound(i + 1);
            if (it == all.end() || *it > L) break;
            ds.join(i, *it);
            all.erase(it);
        }
    }
    set<int> s;
    for (int i = 0; i < n; i++) s.insert(ds.root(i));
    cout << s.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}