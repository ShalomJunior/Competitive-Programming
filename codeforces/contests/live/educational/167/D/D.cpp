#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6;
const int INF = 1e18;
class segtree {
public:
    struct node {
        int a;
        int b;
        node() {
            a = INF;
            b = 0;
        }
        node(int _a, int _b) {
            a = _a;
            b = _b;
        }
    };

    node unite(const node& x, const node& y) const {
        node res;
        return x.a - x.b < y.a - y.b ? x : y;
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

pair<int, int> get(int a, int b, int c) {
    int lost = a - b;
    int delta = c - a;
    int k = delta / lost;
    c -= k * lost;
    while (c >= a) {
        c -= lost;
        k++;
    }
    return { k, c };
}

using node = segtree::node;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), g(m);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    for (auto& c : g) cin >> c;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = { a[i], b[i] };
    }
    sort(p.begin(), p.end());
    segtree sg(n);
    for (int i = 0; i < n; i++) {
        sg.update(i, node(p[i].first, p[i].second));
    }
    int j = -1;
    vector<int> dp(N + 1);
    for (int i = 0; i <= N; i++) {
        while (j + 1 < n && p[j + 1].first <= i) j++;
        if (j < 0) continue;
        auto f = sg.query(0, j);
        auto res = get(f.a, f.b, i);
        dp[i] = res.first * 2 + dp[res.second];
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int val = g[i];
        if (val > N) {
            auto f = sg.query(0, n - 1);
            auto res = get(f.a, f.b, val);
            ans += res.first * 2 + dp[res.second];
        }
        else {
            ans += dp[val];
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}


/*
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}*/