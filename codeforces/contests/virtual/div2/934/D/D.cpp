#include <bits/stdc++.h>
using namespace std;

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
        //cerr << from << " ->  " << to << endl;
        assert(0 <= from && from <= to && to <= n - 1);
        return submod(pref[to + 1], mulmod(pref[from], pw[to - from + 1]));
    }
};

uint64_t hash61::step = (md >> 2) + rng() % (md >> 1);
vector<uint64_t> hash61::pw = vector<uint64_t>(1, 1);

template<typename T>
const T Max(const T& a, const T& b) {
    return max(a, b);
}

template<typename T, const T(*op)(const T&, const T&)>
class sparseTable {
public:
    vector<vector<T>> st;
    sparseTable(vector<T> vals) {
        int n = vals.size();
        int rows = __lg(n) + 1;
        st.resize(rows);
        st[0] = vals;
        for (int j = 1; j < rows; j++) {
            st[j].resize(n);
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[j][i] = op(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    T query(int l, int r) {
        int j = __lg(r - l + 1);
        return op(st[j][l], st[j][r - (1 << j) + 1]);
    }
};

void solve() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    string r = s;
    reverse(r.begin(), r.end());
    auto get = [&](int l, int r) {
        return make_pair(n - 1 - r, n - 1 - l);
        };
    hash61 hs(s);
    hash61 hr(s);
    vector<int> odds(n, 1);
    auto f = [&](int i, int mid) {
        auto coor = get(i + 1, i + mid);
        return hs(i - mid, i - 1) != hr(coor.first, coor.second);
        };
    for (int i = 0; i < n; i++) {
        int L = 1, R = min(i, n - 1 - i);
        while (L < R) {
            int mid = (L + R) / 2;
            if (f(i, mid)) {
                if (L == mid) f(i, R) ? L = R : R = L;
                else L = mid;
            }
            else R = mid - 1;
        }
        if (L == R)odds[i] = 2 * L + 1;
    }
    vector<int> evens(n);
    auto g = [&](int i, int mid) {
        auto coor = get(n - 1 - (i + 2 + mid - 1), n - 1 - (i + 2));
        return hs(i - mid, i - 1) == hr(coor.first, coor.second);
        };
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1])continue;
        evens[i] = 2;
        int L = 1, R = min(i, n - 1 - (i + 1));
        while (L < R) {
            int mid = (L + R) / 2;
            if (g(i, mid)) {
                if (L == mid)g(i, R) ? L = R : R = L;
                else L = mid;
            }
            else R = mid - 1;
        }
        if (L == R)evens[i] = 2 * L + 2;
    }
    sparseTable<int, Max> o(odds);
    sparseTable<int, Max> e(evens);
    while (q--) {
        //cerr << "q = " << q << endl;
        int l, r;
        cin >> l >> r;
        --l, --r;
        int len = r - l + 1;
        long long ans = 0;
        int lo = 0, ro = (len - 1) / 2;
        while (lo < ro) {
            int mid = (lo + ro) / 2;
            if (o.query(l + mid, r - mid) >= mid) {
                if (lo == mid)o.query(l + ro, r - ro) >= ro ? lo = ro : ro = lo;
                else lo = mid;
            }
            else ro = mid - 1;
        }
        //cerr << "Where" << endl;
        cerr << "lo = " << lo << endl;
        ans += max(1LL * (lo + 1) * (lo + 1), 1LL);
        int le = 1, re = len / 2;
        while (le < re) {
            int mid = (le + re) / 2;
            //cerr << le << " " << mid << " " << re << endl;
            if (e.query(l + mid - 1, r - mid) >= mid) {
                if (le == mid)e.query(l + re - 1, r - re) >= re ? le = re : re = le;
                else le = mid;
            }
            else re = mid - 1;
        }
        cerr << "re = " << re << endl;
        ans += 1LL * re * (re + 1);
        int all = 1LL * len * (len + 1) / 2;
        cerr << "all = " << all << endl;
        cerr << all - ans << endl;
        //cerr << 1LL * len * (len + 1) / 2 - ans << endl;
        //cout << endl;
    }
    cout << endl << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}

// string s = "hallopersohellodevhello";
// string p = "hello";
// int n = s.length();
// int m = p.length();
// hash61 hs(s);
// hash61 hp(p);
// for (int i = 0; i + m <= n; i++) {
//     cout << "i = " << i << endl;
//     if (hs(i, i + m - 1) == hp(0, m - 1)) {
//         cerr << "We got something " << endl;
//         if (s.substr(i, m) == p) {
//             cout << "Really" << endl;

//         }
//         else {
//             cout << "Unlike" << endl;
//         }
//     }
// }