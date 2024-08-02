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
        assert(0 <= from && from <= to && to <= n - 1);
        return submod(pref[to + 1], mulmod(pref[from], pw[to - from + 1]));
    }
};

uint64_t hash61::step = (md >> 2) + rng() % (md >> 1);
vector<uint64_t> hash61::pw = vector<uint64_t>(1, 1);

#define int long long
const int N = 26;

int f(int n) {
    n -= n % 2;
    int k = n / 2;
    return k * (k + 1);
}

int g(int n) {
    return n * (n + 1) / 2 - f(n);
}

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    string o, e;
    for (int i = 0; i < n; i++) {
        i & 1 ? o.push_back(s[i]) : e.push_back(s[i]);
    }
    auto r = s;
    reverse(r.begin(), r.end());
    hash61 hs(s), hr(r), ho(o), he(e);
    auto is = [&](int l, int r) {
        int nl = n - 1 - r;
        int nr = n - 1 - l;
        return hs(l, r) == hr(nl, nr);
        };

    vector<hash61> h;
    for (int i = 0; i < N; i++) {
        h.push_back(hash61(string(n, 'a' + i)));
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int len = r - l + 1;
        if (len == 1) {
            cout << 0 << endl;
            continue;
        }
        int ans = is(l, r) ? 0 : len;
        int j = s[l] - 'a';
        if (h[j](0, len - 1) != hs(l, r)) {
            ans += f(len);
            if (len % 2 == 0)
                ans -= len;
        }
        int x = (len + 1) / 2;
        int y = len / 2;
        bool flag = true;
        if (l & 1) {
            if (ho(l / 2, l / 2 + x - 1) != h[j](0, x - 1)) flag = false;
            if (he((l + 1) / 2, (l + 1) / 2 + y - 1) != h[s[l + 1] - 'a'](0, y - 1)) flag = false;
        }
        else {
            if (he(l / 2, l / 2 + x - 1) != h[j](0, x - 1)) flag = false;
            if (ho(l / 2, l / 2 + y - 1) != h[s[l + 1] - 'a'](0, y - 1)) flag = false;
        }
        if (!flag) {
            ans += g(len) - 1;
            if (len % 2)
                ans -= len;
        }
        cout << ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}



/*

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    string o, e;
    for (int i = 0; i < n; i++) {
        i & 1 ? o.push_back(s[i]) : e.push_back(s[i]);
    }
    auto r = s;
    reverse(r.begin(), r.end());
    hash61 hs(s), hr(r), ho(o), he(e);
    auto is = [&](int l, int r) {
        int nl = n - 1 - r;
        int nr = n - 1 - l;
        return hs(l, r) == hr(nl, nr);
        };

    vector<hash61> h;
    for (int i = 0; i < N; i++) {
        h.push_back(hash61(string(n, 'a' + i)));
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int len = r - l + 1;
        if (len == 1) {
            cout << 0 << endl;
            continue;
        }
        cerr << l << " -> " << r << endl;
        int ans = is(l, r) ? 0 : len;
        cerr << "1 ans " << ans << endl;
        int j = s[l] - 'a';
        if (h[j](0, len - 1) != hs(l, r)) {
            ans += f(len);
            if (len % 2 == 0)
                ans -= len;
        }
        cerr << "2 ans " << ans << endl;

        int x = (len + 1) / 2;
        int y = len / 2;
        bool flag = true;
        if (l & 1) {
            if (ho(l / 2, l / 2 + x - 1) != h[j](0, x - 1)) flag = false;
            if (he((l + 1) / 2, (l + 1) / 2 + y - 1) != h[s[l + 1] - 'a'](0, y - 1)) flag = false;
        }
        else {
            if (he(l / 2, l / 2 + x - 1) != h[j](0, x - 1)) flag = false;
            if (ho(l / 2, l / 2 + y - 1) != h[s[l + 1] - 'a'](0, y - 1)) flag = false;
        }
        if (!flag) {
            ans += g(len) - 1;
            if (len % 2)
                ans -= len;
        }
        cerr << "3 ans " << ans << endl;
        cout << ans << endl;
    }
}*/
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