#include <bits/stdc++.h>
#define int long long
using namespace std;

template<typename T>
const T Max(const T& a, const T& b) { return max(a, b); }

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
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]] = i;
    }
    sparseTable<int, Max> g(a);
    vector<int> l(n + 1);
    for (int i = 1; i <= n; i++) {
        int L = 1, R = i;
        while (L < R) {
            int mid = (L + R) / 2;
            g.query(mid, i) <= a[i] ? R = mid : L = mid + 1;
        }
        l[a[i]] = R;
    }
    vector<int> r(n + 1);
    for (int i = 1; i <= n; i++) {
        int L = i, R = n;
        while (L < R) {
            int mid = (L + R) / 2;
            if (g.query(i, mid) <= a[i]) {
                if (L == mid) g.query(i, R) <= a[i] ? L = R : R = L;
                else L = mid;
            }
            else R = mid - 1;
        }
        r[a[i]] = L;
    }
    int ans = 0;
    for (int mx = 1; mx <= n; mx++) {
        int x = l[mx];
        int y = r[mx];
        int j = b[mx];
        assert(g.query(x, y) == mx);
        if (j - x < y - j) {
            for (int k = x; k < j; k++) {
                int i = b[mx - a[k]];
                if (j < i&& i <= y)
                    ans++;
            }
        }
        else {
            for (int k = y; k > j; k--) {
                int i = b[mx - a[k]];
                if (x <= i && i < j)
                    ans++;
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
