#include <bits/stdc++.h>
using namespace std;

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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sparseTable<int, min> sp(a);
    while (q--) {
        int l, r; cin >> l >> r;
        cout << sp.query(l, r) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
}
