#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

template<typename T>
const T Max(const T& a, const T& b) {
    return max(a, b);
}

template<typename T>
const T Min(const T& a, const T& b) {
    return min(a, b);
}

template<typename T, const T(*op)(const T&, const T&)>
class SparseTable {
public:
    vector<vector<T>> st;
    SparseTable(vector<T> vals) {
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
    int n; cin >> n;
    vector<int> a(n);
    vector<vector<int>> id(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = x;
        id[x].push_back(i);
    }
    vector<int> b(n);
    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        c[i] = { b[i], i };
    }
    sort(c.begin(), c.end());
    SparseTable<int, Max> g(a);
    SparseTable<int, Min> f(b);
    for (int i = 0; i < n; i++) {
        int v = c[i].F, j = c[i].S;
        auto it = lower_bound(id[v].begin(), id[v].end(), j);
        if (it != id[v].end()) {
            int M = g.query(j, *it);
            if (M == v && f.query(j, *it) >= v) continue;
        }
        if (it != id[v].begin()) {
            --it;
            int M = g.query(*it, j);
            if (M == v && f.query(*it, j) >= v) continue;
        }
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
