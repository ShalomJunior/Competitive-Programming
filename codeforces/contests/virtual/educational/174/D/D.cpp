#include <bits/stdc++.h>
using namespace std;

const int N = 26;
const int INF = 1e9;
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

int go(string a) {
    int n = a.length();
    int l = 0;
    int r = n - 1;
    while (r >= 0 && a[l] == a[r]) l++, r--;
    if (l > r) return 0;
    a = a.substr(l, r - l + 1);
    n = a.length();
    string b = a;
    reverse(b.begin(), b.end());
    hash61 ha(a), hb(b);
    auto is = [&](int l, int r) {
        int nl = n - 1 - r;
        int nr = n - 1 - l;
        return ha(l, r) == hb(nl, nr);
        };
    vector<int> cnt(N);
    for (auto& c : a) cnt[c - 'a']++;
    vector<int> L(N);
    vector<int> R(N);
    for (int i = 0; i < n; i++) {
        L[a[i] - 'a']++;
        R[a[n - 1 - i] - 'a']++;
        int k = (n - 1) / 2;
        if (i >= k) {
            bool flag = true;
            for (int j = 0; j < N; j++) {
                flag &= 2 * L[j] >= cnt[j];
            }
            if (flag) return i + 1;
        }
        else {
            bool flag = true;
            for (int j = 0; j < N; j++) {
                flag &= L[j] == R[j];
            }
            if (flag && is(i + 1, n - (i + 2))) return i + 1;
        }
    }
    assert(false);
    return INF;
}

void solve() {
    string a;
    cin >> a;
    string b = a;
    reverse(b.begin(), b.end());
    cout << min(go(a), go(b)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}