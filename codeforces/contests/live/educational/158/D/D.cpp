#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
class segtree {
public:
    struct node {
        int val;
        node() : val(0) {}
        node(int _val) : val(_val) {}
    };

    node unite(const node& a, const node& b) const {
        node res;
        res.val = max(a.val, b.val);
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
            tree[v].val = val;
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

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r).val;
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    segtree sg(n + 1);
    for (int i = 0; i < n; i++) sg.update(i, a[i] + i);
    int mn = INF;
    for (int i = 0; i < n; i++) {
        int c = a[i];
        if (i > 0)
            c = max(c, sg.query(0, i - 1) + n - 1);
        if (i < n - 1)
            c = max(c, sg.query(i + 1, n - 1));
        mn = min(mn, c);
        sg.update(i, a[i] - i);
    }
    cout << mn << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
