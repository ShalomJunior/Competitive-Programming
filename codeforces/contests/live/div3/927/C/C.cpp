#include <bits/stdc++.h>
#define int long long
using namespace std;

int MOD;
class segtree {
public:
    struct node {
        int val = 1;
    };
    node unite(const node& a, const node& b) const {
        node res;
        res.val = (a.val * b.val) % MOD;
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
            tree[v].val = val % MOD;
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    string s;
    cin >> s;
    MOD = m;
    segtree sg(n);
    for (int i = 0; i < n; i++)sg.update(i, a[i]);
    int l = 0, r = n - 1;
    for (int i = 0; i < n; i++) {
        cout << sg.query(l, r).val << " ";
        (s[i] == 'L') ? l++ : r--;
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
