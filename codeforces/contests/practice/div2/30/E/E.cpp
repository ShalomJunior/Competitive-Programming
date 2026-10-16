#include<bits/stdc++.h>
using namespace std;

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

void solve() {
    string s;
    cin >> s;
    auto r = s;
    reverse(r.begin(), r.end());
    hash61 hs(s);
    hash61 hr(r);
    int n = s.length();
    auto rev = [&](int l, int r) {
        int nl = n - 1 - r;
        int nr = n - 1 - l;
        return hr(nl, nr);
        };
    vector<int> occ(n + 1, INF);
    occ[0] = 0;
    for (int i = n - 1, j = 0; i >= 0; i--) {
        int len = n - i;
        auto g = rev(i, n - 1);
        while (j + len - 1 <= n - 1 && hs(j, j + len - 1) != g) j++;
        if ((j + len - 1 <= n - 1) && (j + len - 1 < i))
            occ[len] = j;
    }
    int len = 0;
    vector<pair<int, int>> ans;
    auto go = [&](int id, int mid) {
        if (mid == 0) return true;
        auto f = hs(id - mid, id - 1);
        auto g = rev(id + 1, id + mid);
        return f == g;
        };
    for (int i = 0; i < n; i++) {
        int L = 0, R = min(i, n - (i + 1));
        while (L < R) {
            int mid = (L + R) / 2;
            if (go(i, mid)) {
                if (L == mid) go(i, R) ? L = R : R = L;
                else L = mid;
            }
            else R = mid - 1;
        }
        int middle = L;
        int x = i - middle;
        int y = i + middle;
        L = 0, R = min(x, n - (y + 1));
        while (L < R) {
            int mid = (L + R) / 2;
            if (occ[mid] + mid - 1 < x) {
                if (L == mid) {
                    occ[R] + R - 1 < x ? L = R : R = L;
                }
                else L = mid;
            }
            else {
                R = mid - 1;
            }
        }
        int tot = 2 * L + 2 * middle + 1;
        if (tot > len) {
            ans.clear();
            if (L) {
                ans.push_back({ occ[L] + 1 , L });
            }
            ans.push_back({ i - middle + 1, 2 * middle + 1 });
            if (L) {
                ans.push_back({ n - L + 1, L });
            }
            len = tot;
        }
    }
    cout << ans.size() << endl;
    for (auto& [id, z] : ans) cout << id << " " << z << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

/*

#include<bits/stdc++.h>
using namespace std;

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

void solve() {
    string s;
    cin >> s;
    auto r = s;
    reverse(r.begin(), r.end());
    hash61 hs(s);
    hash61 hr(r);
    int n = s.length();
    auto rev = [&](int l, int r) {
        int nl = n - 1 - r;
        int nr = n - 1 - l;
        return hr(nl, nr);
        };
    vector<int> occ(n + 1, INF);
    occ[0] = 0;
    for (int i = n - 1, j = 0; i >= 0; i--) {
        int len = n - i;
        auto g = rev(i, n - 1);
        while (j + len - 1 <= n - 1 && hs(j, j + len - 1) != g) j++;
        cerr << j + len - 1 << " -> " << i << endl;
        if ((j + len - 1 <= n - 1) && (j + len - 1 < i))
            occ[len] = j;
    }
    for (auto& c : occ) cerr << c << " ";
    cerr << endl;
    int len = 0;
    vector<pair<int, int>> ans;
    auto go = [&](int id, int mid) {
        if (mid == 0) return true;
        auto f = hs(id - mid, id - 1);
        auto g = rev(id + 1, id + mid);
        return f == g;
        };
    for (int i = 0; i < n; i++) {
        cerr << "i = " << i << endl;
        int L = 0, R = min(i, n - (i + 1));
        while (L < R) {
            cerr << L << " # " << R << endl;
            int mid = (L + R) / 2;
            if (go(i, mid)) {
                if (L == mid) go(i, R) ? L = R : R = L;
                else L = mid;
            }
            else R = mid - 1;
        }
        cerr << "ass" << endl;
        int middle = L;
        cerr << "middle " << middle << endl;
        int x = i - middle;
        int y = i + middle;
        L = 0, R = min(x, n - (y + 1));
        while (L < R) {
            int mid = (L + R) / 2;
            if (occ[mid] + mid - 1 < x) {
                if (L == mid) {
                    occ[R] + R - 1 < x ? L = R : R = L;
                }
                else L = mid;
            }
            else {
                R = mid - 1;
            }
        }
        cerr << "pref " << L << endl;
        int tot = 2 * L + 2 * middle + 1;
        cerr << i << " @ " << tot << endl;
        if (tot > len) {
            ans.clear();
            if (L) {
                ans.push_back({ occ[L] + 1 , L });
            }
            ans.push_back({ i - middle + 1, 2 * middle + 1 });
            if (L) {
                ans.push_back({ n - L + 1, L });
            }
            len = tot;
        }
    }
    cout << ans.size() << endl;
    for (auto& [id, z] : ans) cout << id << " " << z << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}*/