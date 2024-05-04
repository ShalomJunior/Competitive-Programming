#include <bits/stdc++.h>
using namespace std;

template<typename T>
const T& Max(const T& a, const T& b) {
    return max(a, b);
}

template<typename T>
const T& Min(const T& a, const T& b) {
    return min(a, b);
}

template<typename T, const T& (*op)(const T&, const T&)>
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    map<int, vector<int>> idx;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        idx[a[i]].push_back(i);
    }
    sparseTable<int, Max> f(a);
    sparseTable<int, Min> g(a);
    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        int mx = f.query(l, r);
        int mn = g.query(l, r);
        if (mn == mx && mx == x) {
            cout << -1 << endl;
            continue;
        }
        int i = *lower_bound(idx[mn].begin(), idx[mn].end(), l) + 1;
        int j = *lower_bound(idx[mx].begin(), idx[mx].end(), l) + 1;
        cout << (a[i - 1] == x ? j : i) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
