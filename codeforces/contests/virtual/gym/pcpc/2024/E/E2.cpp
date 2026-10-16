#include <bits/stdc++.h>
using namespace std;

const int N = 31;

struct Info {
    int val;
    int start;
    int end;
    Info() : val(-1), start(-1), end(-1) {}
    Info(int v, int s, int e) : val(v), start(s), end(e) {}
    bool operator<(const Info& o) const {
        if (val != o.val) return val < o.val;
        if (start != o.start) return start < o.start;
        return end < o.end;
    }
};

class segtree {
public:
    struct node {
        vector<Info> infos;

        node() : infos() {}
    };

    node unite(const node& a, const node& b) const {
        node res;
        merge(a.infos.begin(), a.infos.end(),
            b.infos.begin(), b.infos.end(),
            back_inserter(res.infos));
        return res;
    }

    Info unite(const Info& a, const Info& b) const {
        if (a.val == -1) return b;
        if (b.val == -1) return a;
        if (a.val != b.val) return (a.val < b.val) ? a : b;
        if (a.start != b.start) return (a.start < b.start) ? a : b;
        return (a.end < b.end) ? a : b;
    }

    int n;
    vector<node> tree;

    segtree(int _n, vector<vector<Info>>& a) : n(_n) {
        assert(n > 0);
        tree.resize(4 * n);
        build(0, 0, n - 1, a);
    }

    void build(int v, int tl, int tr, vector<vector<Info>>& a) {
        //cerr << "build " << v << " " << tl << " " << tr << endl;
        if (tl == tr) {
            tree[v].infos = a[tl];
        }
        else {
            int tm = (tl + tr) / 2;
            build(2 * v + 1, tl, tm, a);
            build(2 * v + 2, tm + 1, tr, a);
            tree[v] = unite(tree[2 * v + 1], tree[2 * v + 2]);
        }
    }

    void update(int pos, vector<Info>& val) {
        update(0, 0, n - 1, pos, val);
    }

    void update(int v, int tl, int tr, int pos, vector<Info>& val) {
        if (tl == tr) {
            tree[v].infos = val;
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

    Info query(int l, int r, int L, int R) {
        return query(0, 0, n - 1, l, r, L, R);
    }

    Info query(int v, int tl, int tr, int l, int r, int L, int R) {
        //cerr << "query " << v << " " << tl << " " << tr << " " << l << " " << r << " " << L << " " << R << endl;
        if (l > r) {
            return Info();
        }
        if (tl == l && tr == r) {
            auto it = lower_bound(tree[v].infos.begin(), tree[v].infos.end(), Info(L, -1, -1));
            if (it != tree[v].infos.end() && it->val <= R) {
                return *it;
            }
            return Info();
        }
        int tm = (tl + tr) / 2;
        Info left = query(2 * v + 1, tl, tm, l, min(r, tm), L, R);
        Info right = query(2 * v + 2, tm + 1, tr, max(l, tm + 1), r, L, R);
        return unite(left, right);
    }
};

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int j = n;
    deque<int> p;
    vector<int> next(n + 1, n);
    for (int i = n - 1; i >= 0; i--) {
        next[i] = s[i] == '1' ? i : next[i + 1];
        if (s[i] == '0') {
            next[i] = next[i + 1];
            j = i;
        }
        else {
            next[i] = i;
            p.push_front(i);
        }
    }
    vector<vector<Info>> a(n);
    for (int i = 0; i < n; i++) {
        int val = 0;
        int where = next[i];
        for (int k = 0; k < N && where + k < n; k++) {
            val *= 2;
            if (s[where + k] == '1') {
                val += 1;
                a[i].push_back({ val, i, where + k });
            }
            sort(a[i].begin(), a[i].end());
        }
    }
    segtree sg(n, a);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == 0 && j != n) {
            cout << j + 1 << " " << j + 1 << "\n";
            continue;
        }
        auto [val, ni, nj] = sg.query(0, n - 1, l, r);
        if (val == -1) {
            cout << -1 << " " << -1 << "\n";
            continue;
        }
        cout << ni + 1 << " " << nj + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}