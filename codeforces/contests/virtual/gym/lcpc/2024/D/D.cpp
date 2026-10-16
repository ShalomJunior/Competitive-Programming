#include <bits/stdc++.h>
using namespace std;

template<typename T>
const T GCD(const T& a, const T& b) {
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    set<pair<int, int>> s;
    sparseTable<int, GCD> g(a);
    for (int i = 0; i < n; i++) {
        int last = a[i];
        int j = i;
        while (j < n) {
            int l = j + 1;
            int r = n - 1;
            while (l < r) {
                int m = (l + r) / 2;
                g.query(i, m) == last ? l = m + 1 : r = m;
            }
            s.insert({ l - i, last });
            j = l;
            if (j < n)
                last = g.query(i, j);
        }
    }
    int q;
    cin >> q;
    map<int, vector<int>> pos;
    for (int i = 0; i < q; i++) {
        int len;
        cin >> len;
        pos[len].push_back(i);
    }
    deque<int> dq;
    for (auto& [k, v] : pos) dq.push_front(k);
    vector<int> ans(q);
    int mx = 0;
    for (auto& k : dq) {
        while (!s.empty() && prev(s.end())->first >= k) {
            mx = max(mx, prev(s.end())->second);
            s.erase(prev(s.end()));
        }
        for (auto& i : pos[k]) ans[i] = mx;
    }
    for (auto& c : ans) cout << c << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}