#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
class segtree {
public:
    struct node {
        pair<int, int> mn;
        pair<int, int> mx;
        int ans;
        node() {
            mn = { INF, INF };
            mx = { -INF, -INF };
            ans = 0;
        }
    };

    node unite(const node& a, const node& b) const {
        node res;
        res.mn.first = min(a.mn.first, b.mn.first);
        res.mn.second = min(a.mn.second, b.mn.second);
        res.mx.first = max(a.mx.first, b.mx.first);
        res.mx.second = max(a.mx.second, b.mx.second);
        res.ans = max({ a.ans, b.ans, b.mx.first - a.mn.first, a.mx.second - b.mn.second });
        return res;
    }

    int n;
    vector<node> tree;

    segtree(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(4 * n);
    }

    void update(int pos, node val) {
        update(0, 0, n - 1, pos, val);
    }

    void update(int v, int tl, int tr, int pos, node val) {
        if (tl == tr) {
            tree[v] = val;
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

using node = segtree::node;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    segtree sg(n);
    for (int i = 0; i < n; i++) {
        node val;
        val.mn = val.mx = { a[i] - i, a[i] + i };
        sg.update(i, val);
    }
    cout << sg.query(0, n - 1).ans << endl;
    while (q--) {
        int p, x;
        cin >> p >> x;
        p--;
        a[p] = x;
        node val;
        val.mn = val.mx = { a[p] - p, a[p] + p };
        sg.update(p, val);
        cout << sg.query(0, n - 1).ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}