#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
class segtree {
public:
    struct node {
        int id;
        int t;
        int ram;
        node() : id(0), t(0), ram(0) {}
        node(int _id, int _t, int _ram) : id(_id), t(_t), ram(_ram) {}
        bool operator<(const node& other) const {
            if (t != other.t) return t < other.t;
            if (ram != other.ram) return ram < other.ram;
            return id > other.id;
        }
    };

    node unite(const node& a, const node& b) const {
        node res;
        if (a.t != b.t) return a.t > b.t ? a : b;
        if (a.ram != b.ram) return a.ram > b.ram ? a : b;
        return a.id < b.id ? a : b;
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

void solve() {
    int q;
    cin >> q;
    using node = segtree::node;
    segtree sg(N + 1);
    vector<set<node>> all(N + 1);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int id, t, ram;
            cin >> id >> t >> ram;
            all[ram].insert(node{ id, t, ram });
            sg.update(ram, *prev(all[ram].end()));
        }
        else {
            int free;
            cin >> free;
            node res = sg.query(1, free);
            if (res.id == 0) {
                cout << -1 << endl;
            }
            else {
                cout << res.id << endl;
                all[res.ram].erase(res);
                if (all[res.ram].empty()) {
                    sg.update(res.ram, node());
                }
                else {
                    sg.update(res.ram, *prev(all[res.ram].end()));
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}