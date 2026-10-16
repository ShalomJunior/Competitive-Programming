#include <bits/stdc++.h>
#define int long long
using namespace std;

template<typename T>
const T Max(const T& a, const T& b) {
    return max(a, b);
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
    int n, s, x;
    cin >> n >> s >> x;
    vector<int> a(n + 1);
    vector<int> pref(n + 1);
    vector<int> p;
    map<int, vector<int>> h;
    h[0].push_back(0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == x) p.push_back(i);
        pref[i] = pref[i - 1] + a[i];
        h[pref[i]].push_back(i);
    }
    sparseTable<int, Max> g(a);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (p.empty()) continue;
        auto it = upper_bound(p.begin(), p.end(), i);
        if (it == p.begin()) continue;
        it--;
        int r = *it;
        int lo = 1, hi = r;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            g.query(mid, i) > x ? lo = mid + 1 : hi = mid;
        }
        int l = hi;
        if (l > 0 && g.query(l, i) == x && h.count(pref[i] - s)) {
            auto& v = h[pref[i] - s];
            auto x = lower_bound(v.begin(), v.end(), l - 1);
            auto y = upper_bound(v.begin(), v.end(), r - 1);
            cnt += y - x;
        }
    }
    cout << cnt << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}