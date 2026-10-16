#include <bits/stdc++.h>
#define int long long
using namespace std;

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


int f(int n) {
    return n * (n + 1) / 2;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, vector<int>> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[a[i]].push_back(i);
    }
    sparseTable<int, Min> g(a);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        int mn = g.query(l, r);
        auto& v = p[mn];
        auto it1 = lower_bound(v.begin(), v.end(), l);
        auto it2 = upper_bound(v.begin(), v.end(), r); it2--;
        int i = it1 - v.begin();
        int j = it2 - v.begin();
        if (i == j) {
            cout << 0 << endl;
            continue;
        }
        int ans = f(len) - f(v[i] - l) - f(r - v[j]) - (v[i] - l) * (r - v[j]);
        for (int k = i; k + 1 <= j; k++) {
            ans -= f(v[k + 1] - v[k] - 1);
        }
        ans -= (r - v[j]);
        ans -= (v[i] - l);
        ans--;
        cout << ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}