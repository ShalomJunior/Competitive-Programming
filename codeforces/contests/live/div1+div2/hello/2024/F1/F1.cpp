#include <bits/stdc++.h>
#define int long long
using namespace std;

class segtree {
public:
    struct node {
        int pos, neg;
        node() {
            pos = 0;
            neg = 0;
        }
    };
    node unite(const node& a, const node& b) const {
        node res;
        int take = min(a.pos, b.neg);
        res.pos = a.pos - take + b.pos;
        res.neg = a.neg + b.neg - take;
        return res;
    }
    int n;
    vector<node> tree;
    segtree(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }
    void build(int v, int tl, int tr) {
        if (tl == tr) {}
        else {
            int tm = (tl + tr) / 2;
            build(2 * v + 1, tl, tm);
            build(2 * v + 2, tm + 1, tr);
            tree[v] = unite(tree[2 * v + 1], tree[2 * v + 2]);
        }
    }
    void update(int pos, int val) {
        update(0, 0, n - 1, pos, val);
    }
    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            if (val < 0) {
                tree[v].neg = -val;
                tree[v].pos = 0;
            }
            else {
                tree[v].pos = val;
                tree[v].neg = 0;
            }
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
    cin >> n >> q;
    vector<int> a(n), b(n), c(n - 1);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    for (auto& x : c) cin >> x;
    segtree sg(n);
    for (int i = 0; i < n; i++) {
        sg.update(i, a[i] - b[i]);
    }
    int tot = accumulate(b.begin(), b.end(), 0LL);
    while (q--) {
        int p, x, y;
        int z;
        cin >> p >> x >> y >> z; --p;
        tot += y - b[p];
        a[p] = x, b[p] = y;
        sg.update(p, a[p] - b[p]);
        cout << tot - sg.query(0, n - 1).neg << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}