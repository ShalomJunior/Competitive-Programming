#include <bits/stdc++.h>
using namespace std;

class segtree {
public:
    struct node {
        vector<int> a;
        vector<long long> pref;
        node() {}
    };
    node unite(const node& f, const node& g) const {
        node res;
        res.a.resize(f.a.size() + g.a.size());
        merge(f.a.begin(), f.a.end(), g.a.begin(), g.a.end(), res.a.begin());
        for (int i = 0; i < (int)res.a.size(); i++) {
            res.pref.push_back(res.a[i] + (i > 0 ? res.pref[i - 1] : 0));
        }
        assert(res.a.size() == res.pref.size());
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
            tree[v].a.push_back(val);
            tree[v].pref.push_back(val);
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

    void query(int l, int r, int k, long long& ans) {
        query(0, 0, n - 1, l, r, k, ans);
    }

    void query(int v, int tl, int tr, int l, int r, int k, long long& ans) {
        if (l > r) return;
        if (tl == l && tr == r) {
            auto it = upper_bound(tree[v].a.begin(), tree[v].a.end(), k);
            if (it != tree[v].a.begin()) {
                int idx = it - tree[v].a.begin() - 1;
                assert(tree[v].pref.size() > idx);
                ans += tree[v].pref[idx];
            }
            return;
        }
        int tm = (tl + tr) / 2;
        query(2 * v + 1, tl, tm, l, min(r, tm), k, ans);
        query(2 * v + 2, tm + 1, tr, max(l, tm + 1), r, k, ans);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    segtree sg(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sg.update(i, a[i]);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        long long ans = 0;
        sg.query(l, r, k, ans);
        cout << ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
