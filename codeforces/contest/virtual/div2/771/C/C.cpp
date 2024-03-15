#include <bits/stdc++.h>
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
    int n; cin >> n;
    vector<int> a(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[--a[i]] = i;
    }
    sparseTable<int, Min> f(a);
    sparseTable<int, Max> g(a);
    int ans = 0, r = n - 1, m;
    while (r >= 0) {
        int M = g.query(0, r);
        if (r == n - 1) {
            ans++;
            m = f.query(p[M], n - 1);
        }
        else {
            if (M < m) ans++;
            m = f.query(p[M], n - 1);
        }
        r = p[M] - 1;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}