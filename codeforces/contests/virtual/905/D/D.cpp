#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

const int INF = 1e9;
struct Info {
    int l, r, idx;
    bool operator<(const Info& other) const {
        if (l != other.l) return l < other.l;
        if (r != other.r) return r < other.r;
        return idx < other.idx;
    }
};

int get(int n) {
    int i = 0;
    while ((1 << i) < n) i++;
    return 1 << i;
}

Mine merge(const Mine& a, const Mine& b) {
    if (a.F > b.S || a.S < b.F) {
        return make_pair(-1, -1);
    }
    else {
        return make_pair(max(a.F, b.F), min(a.S, b.S));
    }
}

vector<Mine> build(int n) {
    int N = get(n);
    vector<Mine> ans(2 * N);
    for (int i = 0; i < N; i++) {
        ans[N + i] = make_pair(0, INF);
    }
    for (int i = N - 1; i > 0; i--) {
        ans[i] = merge(ans[2 * i], ans[2 * i + 1]);
    }
    return ans;
}

void update(vector<Mine>& tree, int idx, Mine seg) {
    int N = tree.size() / 2;
    int id = idx + N;
    tree[id] = seg; id /= 2;
    while (id > 0) {
        tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
        id /= 2;
    }
}

Mine query(vector<Mine>& tree, int l, int r) {
    Mine ans = { 0 , INF };
    int N = tree.size() / 2;
    l += N, r += N;
    while (l <= r) {
        if (l & 1) {
            ans = merge(ans, tree[l]);
            l++;
        }
        if (r % 2 == 0) {
            ans = merge(ans, tree[r]);
            r--;
        }
        l /= 2, r /= 2;
    }
    return ans;
}

void solve() {
    int q; cin >> q;
    auto g = build(q);
    set<Info> seg;
    for (int i = 0; i < q; i++) {
        char s; int l, r;
        cin >> s >> l >> r;
        pair<int, int> p = { l, r };
        if (s == '+') {
            update(g, i, p);
            seg.insert(Info{ l, r, i });
        }
        else {
            auto it = seg.lower_bound(Info{ l, r, 0 });
            update(g, it->idx, make_pair(0, INF));
            seg.erase(it);
        }
        auto seg = query(g, 0, q - 1);
        cout << (seg == make_pair(-1, -1) ? "YES" : "NO") << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}