#include<bits/stdc++.h>
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

bool is(string a, string b) {
    int m = a.length();
    int n = b.length();
    if (m < n) {
        swap(a, b);
        swap(m, n);
    }
    hash61 ha(a), hb(b);
    for (int i = 0; i + n - 1 < m; i++) {
        if (ha(i, i + n - 1) == hb(0, n - 1))
            return true;
    }
    return false;
}

void solve() {
    int n = 3;
    vector<string> a(n);
    for (auto& s : a) cin >> s;
    sort(a.begin(), a.end());
    auto get = [](string a, string b) {
        int m = a.length();
        int n = b.length();
        if (is(a, b)) {
            return m > n ? a : b;
        }
        hash61 ha(a), hb(b);
        int len = 0;
        for (int i = 1; i <= min(m, n); i++) {
            if (ha(m - i, m - 1) == hb(0, i - 1))
                len = i;
        }
        return a + (len < n ? b.substr(len, n - len) : 0);
        };
    int ans = 1e9;
    do {
        auto s = get(get(a[0], a[1]), a[2]);
        int curr = s.size();
        ans = min(ans, curr);
    } while (next_permutation(a.begin(), a.end()));
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}