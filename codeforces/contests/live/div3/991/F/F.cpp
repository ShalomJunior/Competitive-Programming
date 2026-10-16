#include <bits/stdc++.h>
#define int long long
using namespace std;

template<typename T>
const T Gcd(const T& a, const T& b) {
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> b(n);
    for (int i = 1; i < n; i++) b[i] = abs(a[i] - a[i - 1]);
    sparseTable<int, Gcd> g(b);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l == r) {
            cout << 0;
        }
        else {
            cout << g.query(l + 1, r);
        }
        cout << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
