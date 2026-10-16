#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
class segtree {
public:
    struct node {
        int id;
        int cnt;
        node() : id(INF), cnt(INF) {}
        node(int _id, int _cnt) : id(_id), cnt(_cnt) {}
    };

    node unite(const node& a, const node& b) const {
        node res;
        if (a.cnt < b.cnt)
            res = a;
        else if (a.cnt == b.cnt)
            res = a.id > b.id ? a : b;
        else
            res = b;
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
        if (tl == tr) {
            tree[v].id = tl;
            tree[v].cnt = 0;
        }
        else {
            int tm = (tl + tr) / 2;
            build(2 * v + 1, tl, tm);
            build(2 * v + 2, tm + 1, tr);
            tree[v] = unite(tree[2 * v + 1], tree[2 * v + 2]);
        }
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

void solve() {
    int q, x;
    cin >> q >> x;
    segtree sg(x);
    vector<int> a(x);
    for (int i = 0; i < q; i++) {
        int y;
        cin >> y;
        y %= x;
        a[y]++;
        sg.update(y, segtree::node(y, a[y]));
        auto res = sg.query(0, x - 1);
        cerr << res.id << " " << res.cnt << endl;
        cout << res.id * res.cnt + 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}