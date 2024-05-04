#include <bits/stdc++.h>
using namespace std;

class segtree {
public:
    struct node {
        int val;
        node() {
            val = 0;
        }
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    segtree sg(n);
    for (int i = 0; i < n; i++)sg.update(i, a[i]);
    k--;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = a[i];
        int r = a[k];
        sg.update(i, r);
        sg.update(k, l);
        int L = i, R = n - 1;
        while (L < R) {
            int mid = (L + R) / 2;
            if (sg.query(i, mid).val == r) {
                if (L == mid) sg.query(i, R).val == r ? L = R : R = L;
                else L = mid;
            }
            else R = mid - 1;
        }
        if ((i == 0 || sg.query(0, i - 1).val < r)) {
            int curr = i ? 1 : 0;
            if (sg.query(i, L).val == r)
                curr += L - i;
            ans = max(ans, curr);
        }
        sg.update(i, l);
        sg.update(k, r);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}