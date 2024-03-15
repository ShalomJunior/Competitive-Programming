#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5;
class segtree {
public:
    struct node {
        string s;
        int cnt;
        int mx;
        int tot;
        node() : s(""), cnt(0), mx(0), tot(0) {}
    };
    node unite(const node& a, const node& b) const {
        node res;
        if (a.cnt != b.cnt) {
            res = a.cnt > b.cnt ? a : b;
        }
        else if (a.mx != b.mx) {
            res = a.mx > b.mx ? a : b;
        }
        else {
            res = a.s < b.s ? a : b;
        }
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
        if (tl == tr) tree[v] = node();
        else {
            int tm = (tl + tr) / 2;
            build(2 * v + 1, tl, tm);
            build(2 * v + 2, tm + 1, tr);
            tree[v] = unite(tree[2 * v + 1], tree[2 * v + 2]);
        }
    }
    void update(int pos, string s, int val) {
        update(0, 0, n - 1, pos, s, val);
    }
    void update(int v, int tl, int tr, int pos, string s, int val) {
        if (tl == tr) {
            tree[v].s = s;
            tree[v].cnt++;
            tree[v].mx = max(tree[v].mx, val);
            tree[v].tot += val;
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(2 * v + 1, tl, tm, pos, s, val);
            }
            else {
                update(2 * v + 2, tm + 1, tr, pos, s, val);
            }
            tree[v] = unite(tree[2 * v + 1], tree[2 * v + 2]);
        }
    }
    node query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
    node query(int v, int tl, int tr, int l, int r) {
        if (l > r) return node();
        if (tl == l && tr == r) return tree[v];
        int tm = (tl + tr) / 2;
        node left = query(2 * v + 1, tl, tm, l, min(r, tm));
        node right = query(2 * v + 2, tm + 1, tr, max(l, tm + 1), r);
        return unite(left, right);
    }
};

void solve() {
    int q;
    cin >> q;
    segtree sg(N);
    map<string, int> idx;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            string s;
            int price;
            cin >> s >> price;
            if (!idx.count(s)) idx[s] = idx.size();
            sg.update(idx[s], s, price);
        }
        else {
            string ans = sg.query(0, N - 1).s;
            // assert(ans.size() != 1);
            cout << ans << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}