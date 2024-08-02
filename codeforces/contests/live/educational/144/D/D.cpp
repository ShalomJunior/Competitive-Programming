#include <bits/stdc++.h>
#define int long long
using namespace std;

template<typename T>
const T& Max(const T& a, const T& b) {
    return max(a, b);
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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] - x;
    }
    if (x < 0) {
        auto f = [&](int l, int r) {
            int best = 0;
            int curr = 0;
            for (int i = 1; i <= n; i++) {
                int val = (i <= l || i >= r) ? a[i] + x : a[i] - x;
                curr = max(curr + val, val);
                best = max(best, curr);
            }
            return best;
            };
        int ans = 0;
        for (int i = 0; i <= k; i++) {
            ans = max(ans, f(i, n - (k - i) + 1));
        }
        cout << ans << endl;
    }
    else {
        vector<int> pref(n + 1);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + b[i];
        }
        vector<int> suff(n + 2);
        for (int i = n; i > 0; i--) {
            suff[i] = suff[i + 1] + b[i];
        }
        auto f = [&](int l, int r) {
            int best = 0;
            int curr = 0;
            for (int i = l; i <= r; i++) {
                curr = max(curr + a[i] + x, a[i] + x);
                best = max(best, curr);
            }
            return best;
            };
        sparseTable<int, Max> L(pref);
        sparseTable<int, Max> R(suff);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int l = i;
            int r = min(i + k - 1, n);
            ans = max(ans, f(l, r));
            int center = (pref[r] - pref[l - 1]) + (r - l + 1) * (2 * x);
            int left = l == 1 ? 0 : R.query(1, l - 1) - suff[l];
            left = max(left, 0LL);
            int right = r == n ? 0 : L.query(r + 1, n) - pref[r];
            right = max(right, 0LL);
            ans = max(ans, left + center + right);
        }
        cout << ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}