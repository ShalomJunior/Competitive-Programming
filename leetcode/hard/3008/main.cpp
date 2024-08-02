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

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int x = s.length();
        int y = a.length();
        int z = b.length();
        hash61 hs(s), ha(a), hb(b);
        vector<int> p, q;
        for (int i = 0; i < x; i++) {
            if (i + y - 1 < x && hs(i, i + y - 1) == ha(0, y - 1))
                p.push_back(i);
            if (i + z - 1 < x && hs(i, i + z - 1) == hb(0, z - 1))
                q.push_back(i);
        }
        vector<int> res;
        if (p.empty() || q.empty()) return res;
        for (auto& c : p) {
            auto it = lower_bound(q.begin(), q.end(), c);
            bool flag = false;
            if (it != q.end() && abs(c - *it) <= k) flag = true;
            if (it != q.begin() && abs(c - *(--it)) <= k) flag = true;
            if (flag) res.push_back(c);
        }
        return res;
    }
};