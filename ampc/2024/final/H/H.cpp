#include <bits/stdc++.h>
#define int long long
using namespace  std;

const int INF = 1e9;
class segtree {
public:
    struct node {
        int id;
        int val;
        int sum;
        node() : id(-INF), val(-INF), sum(0) {}
        node(int _id, int _val) : id(_id), val(_val), sum(_val) {}
    };

    node unite(const node& a, const node& b) const {
        node res = a.val > b.val ? a : b;
        res.sum = a.sum + b.sum;
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
    segtree sg(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sg.update(i, node(i, a[i]));
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            cout << sg.query(l, r).sum << endl;
        }
        else if (t == 2) {
            int k, x;
            cin >> k >> x;
            k--;
            a[k] = x;
            sg.update(k, node(k, x));
        }
        else {
            int l, r, mod;
            cin >> l >> r >> mod;
            --l;
            --r;
            do {
                auto res = sg.query(l, r);
                if (res.id == -INF || a[res.id] < mod) break;
                a[res.id] %= mod;
                sg.update(res.id, node(res.id, a[res.id]));
            } while (true);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}