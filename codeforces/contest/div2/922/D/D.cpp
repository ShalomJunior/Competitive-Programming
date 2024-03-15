#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
class segtree {
public:
    struct node {
        int val;
        node() {
            val = INF;
        }
    };
    node unite(const node& a, const node& b) const {
        node res;
        res.val = min(a.val, b.val);
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
        if (tl == tr) { tree[tl] = node(); }
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
    int n; cin >> n;
    vector<int> a(n + 2), pre(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    pre[n + 1] = pre[n];
    auto go = [&](int mid) {
        vector<int> dp(n + 2);
        segtree sg(n + 2);
        sg.update(0, 0);
        for (int i = 1; i <= n + 1; i++) {
            dp[i] = dp[i - 1] + a[i];
            int l = 0, r = i - 1;
            while (l < r) {
                int m = (l + r) / 2;
                if (pre[i] - a[i] - pre[m] <= mid) {
                    r = m;
                }
                else l = m + 1;
            }
            if (pre[i] - a[i] - pre[r] <= mid) {
                dp[i] = min(dp[i], sg.query(r, i).val + a[i]);
            }
            sg.update(i, dp[i]);
        }
        return dp[n + 1] <= mid;
        };
    int L = 0, R = 1e15;
    while (L < R) {
        int mid = (L + R) / 2;
        go(mid) ? R = mid : L = mid + 1;
    }
    cout << L << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
