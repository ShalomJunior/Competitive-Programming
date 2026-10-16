#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
class segtree {
public:
    struct node {
        int mn;
        int mx;
        node() : mn(INF), mx(-INF) {}
    };
    node unite(const node& a, const node& b) const {
        node res;
        res.mn = min(a.mn, b.mn);
        res.mx = max(a.mx, b.mx);
        return res;
    }
    int n;
    vector<node> tree;
    segtree(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(4 * n);
    }
    void update(int pos, int val) {
        update(0, 0, n - 1, pos, val);
    }
    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            tree[v].mn = val;
            tree[v].mx = val;
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(2 * v + 1, tl, tm, pos, val);
            }
            else {
                update(2 * v + 2, tm + 1, tr, pos, val);
            }
            tree[v] = unite(tree[2 * v + 1], tree[2 * v + 2]);
        }
    }
    node query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
    node query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return node();
        }
        if (tl == l && tr == r) {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        node left = query(2 * v + 1, tl, tm, l, min(r, tm));
        node right = query(2 * v + 2, tm + 1, tr, max(l, tm + 1), r);
        return unite(left, right);
    }
};

void solve() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    s = "." + s;
    segtree sg(n + 1);
    vector<int> a(n + 1);
    unordered_map<int, vector<int>> h;
    for (int i = 1, u = 0; i <= n; i++) {
        u += s[i] == '*' ? 1 : -1;
        a[i] = u;
        sg.update(i, a[i]);
        h[a[i]].push_back(i);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int k = a[l - 1] - 1;
        auto& v = h[k];
        auto it = lower_bound(v.begin(), v.end(), l);
        int j = it == v.end() ? r : *it;
        j = min(j, r);
        int ans = 1;
        assert(l <= j);
        auto [mn, mx] = sg.query(l, j);
        if (mx > a[l - 1])
            ans += mx - a[l - 1];
        if (mn < a[l - 1])
            ans++;
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}