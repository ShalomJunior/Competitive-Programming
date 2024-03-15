#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
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
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    sparseTable<int, Max> f(a);
    sparseTable<int, Min> g(a);
    vector<int> ans(n + 1, INF);
    auto check = [&](int l, int r, int i) {
        int s = pre[r] - pre[l - 1];
        if (s <= a[i]) return false;
        return f.query(l, r) != g.query(l, r) || f.query(l, r) > a[i];
        };
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            int L = 1, R = i - 1;
            while (L < R) {
                int mid = (L + R) / 2;
                if (check(mid, i - 1, i)) {
                    if (L == mid) check(R, i - 1, i) ? L = R : R = L;
                    else L = mid;
                }
                else R = mid - 1;
            }
            if (check(L, i - 1, i)) ans[i] = min(ans[i], i - L);
        }
        if (i < n) {
            int L = i + 1, R = n;
            while (L < R) {
                int mid = (L + R) / 2;
                check(i + 1, mid, i) ? R = mid : L = mid + 1;
            }
            if (check(i + 1, R, i)) ans[i] = min(ans[i], R - i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << (ans[i] == INF ? -1 : ans[i]) << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
