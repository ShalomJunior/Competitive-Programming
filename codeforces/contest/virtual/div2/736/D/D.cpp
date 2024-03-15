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
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> b(n);
    for (int i = 0; i < n - 1; i++) {
        b[i] = abs(a[i + 1] - a[i]);
    }
    sparseTable<int, Gcd> g(b);
    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        int L = i, R = n - 2;
        while (L < R) {
            int mid = (L + R) / 2;
            if (g.query(i, mid) == 1) R = mid - 1;
            else {
                if (L == mid) g.query(i, R) == 1 ? R = L : L = R;
                else L = mid;
            }
        }
        if (L > i || b[i] > 1) L++;
        ans = max(ans, L - i + 1);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}