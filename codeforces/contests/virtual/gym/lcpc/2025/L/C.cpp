#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5;
const int INF = 1e18;
class segtree {
public:
    struct node {
        int val = 0;
        node() : val(INF) {};
        node(int val) : val(val) {};
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

uint64_t rng() {
    static mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<uint64_t> distribution(0, numeric_limits<uint64_t>::max());
    return distribution(generator);
}

struct hash61 {
    static const uint64_t md = (1LL << 61) - 1;
    static uint64_t step;
    static vector<uint64_t> pw;

    uint64_t addmod(uint64_t a, uint64_t b) const {
        a += b;
        if (a >= md) a -= md;
        return a;
    }

    uint64_t submod(uint64_t a, uint64_t b) const {
        a += md - b;
        if (a >= md) a -= md;
        return a;
    }

    uint64_t mulmod(uint64_t a, uint64_t b) const {
        uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
        uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
        uint64_t ret = (l & md) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
        ret = (ret & md) + (ret >> 61);
        ret = (ret & md) + (ret >> 61);
        return ret - 1;
    }

    void ensure_pw(int sz) {
        int cur = (int)pw.size();
        if (cur < sz) {
            pw.resize(sz);
            for (int i = cur; i < sz; i++) {
                pw[i] = mulmod(pw[i - 1], step);
            }
        }
    }

    vector<uint64_t> pref;
    int n;

    template<typename T>
    hash61(const T& s) {
        n = (int)s.size();
        ensure_pw(n + 1);
        pref.resize(n + 1);
        pref[0] = 1;
        for (int i = 0; i < n; i++) {
            pref[i + 1] = addmod(mulmod(pref[i], step), s[i]);
        }
    }

    inline uint64_t operator()(const int from, const int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        return submod(pref[to + 1], mulmod(pref[from], pw[to - from + 1]));
    }
};

uint64_t hash61::step = (md >> 2) + rng() % (md >> 1);
vector<uint64_t> hash61::pw = vector<uint64_t>(1, 1);

string S;
hash61 HS(S);
void init() {
    while (S.size() < N) S += "01";
    HS = hash61(S);
}

bool is(string s) {
    int n = s.length();
    if (n == 1) return false;
    return s == S.substr(0, n) || s == S.substr(1, n);
}
bool is(string& s, hash61& hs, int l, int r) {
    int n = r - l + 1;
    if (n == 1) return false;
    if (n < 10) {
        cout << "* " << s.substr(l, n) << endl;
        return is(s.substr(l, n));
    }
    cerr << HS(0, n) << " " << HS(1, n) << " " << hs(l, r) << endl;
    return HS(0, n) == hs(l, r) || HS(1, n) == hs(l, r);
}

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    s = "#" + s;

    hash61 hs(s);
    vector<int> dp(n + 1, n);
    segtree sg(n + 1);
    dp[0] = 0;
    sg.update(0, 0);
    for (int i = 1; i <= n; i++) {
        cerr << "i = " << i << endl;
        if (k < 0) {
            string t;
            for (int j = 1; j <= k && i - j + 1 >= 1; j++) {
                t += s[i - j + 1];
                if (!is(t)) {
                    dp[i] = min(dp[i], (i - j + 1 > 1 ? 1 : 0) + dp[i - j]);
                }
            }
        }
        else {
            dp[i] = (i > 1 ? 1 : 0) + dp[i - 1];
            int L = max(1LL, i - k + 1), R = i - 1;
            cerr << L << " } " << R << endl;
            while (L < R) {
                int mid = (L + R) / 2;
                if (is(s, hs, mid, i)) {
                    R = mid - 1;
                }
                else {
                    cerr << "not";
                    cerr << L << " | " << R << endl;
                    bool b = is(s, hs, R, i);
                    if (L == mid) is(s, hs, R, i) ? R = L : L = R;
                    else L = mid;
                    cerr << (b ? "Y" : "NO") << L << " | " << R << endl;
                }
            }
            cout << endl;
            cerr << "L  =  " << L << endl;
            cerr << "in" << endl;
            if (!is(s, hs, L, i)) {
                cerr << "L  ĸ " << L << " " << i << endl;
                cout << s.substr(L, i - L + 1);
                if (i - k + 1 <= 1) {
                    dp[i] = 0;
                }
                else {
                    cerr << "shit" << sg.query(max(i - k, 1LL), L - 1).val << endl;
                    dp[i] = min(dp[i], 1 + sg.query(max(i - k, 1LL), L - 1).val);
                }
            }

        }
        sg.update(i, dp[i]);
    }
    for (auto& c : dp) cout << c << " ";
    cout << endl;
    cout << dp[n] << endl;
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin >> t;
    while (t--)solve();
}