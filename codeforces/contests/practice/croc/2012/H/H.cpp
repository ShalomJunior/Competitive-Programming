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

template <typename T>
class prefixSum2d {
public:
    prefixSum2d(const vector<vector<T>>& matrix) : m(matrix.size()), n(matrix[0].size()) {
        ps.resize(m + 1, vector<T>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    T query(int x1, int y1, int x2, int y2) const {
        if (x1 < 0 || y1 < 0 || x2 >= m || y2 >= n) {
            return 0;
        }
        return ps[x2 + 1][y2 + 1] - ps[x1][y2 + 1] - ps[x2 + 1][y1] + ps[x1][y1];
    }
private:
    int m;
    int n;
    vector<vector<T>> ps;
};

// Function to measure the execution time of the code block
double measureExecutionTime(function<void()> codeBlock) {
    // Start time measurement
    auto startTime = chrono::high_resolution_clock::now();

    // Execute the code block
    codeBlock();

    // End time measurement
    auto endTime = chrono::high_resolution_clock::now();

    // Calculate elapsed time in milliseconds
    chrono::duration<double, milli> elapsedTime = endTime - startTime;

    // Return the elapsed time in milliseconds
    return elapsedTime.count();
}

void solve() {
    string s; cin >> s;
    int n = s.length();
    string r = s;
    reverse(r.begin(), r.end());
    hash61 a(s), b(r);
    vector<vector<int>> cnt(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int ni = n - 1 - j;
            int nj = n - 1 - i;
            if (a(i, j) == b(ni, nj)) cnt[i][j]++;
        }
    }
    int q;
    cin >> q;
    prefixSum2d<int> arr(cnt);
    while (q--) {
        int i, j;
        cin >> i >> j;
        i--, j--;
        cout << arr.query(i, i, j, j) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // Measure the execution time
    double executionTime = measureExecutionTime([]() {
        // This lambda block will be timed
        // Put your actual code here
        solve();
        });

    // Print the execution time in milliseconds
    cout << "Execution time: " << executionTime << " milliseconds" << endl;

    return 0;
}

/*


#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TwoDPrefixSum {
public:
    TwoDPrefixSum(const vector<vector<T>>& matrix) : M(matrix.size()), N(matrix[0].size()) {
        PS.resize(M + 1, vector<T>(N + 1, 0));
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                PS[i][j] = PS[i - 1][j] + PS[i][j - 1] - PS[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    T submatrixSum(int x1, int y1, int x2, int y2) const {
        if (x1 < 0 || y1 < 0 || x2 >= M || y2 >= N) {
            return 0;
        }
        return PS[x2 + 1][y2 + 1] - PS[x1][y2 + 1] - PS[x2 + 1][y1] + PS[x1][y1];
    }

private:
    int M;
    int N;
    vector<vector<T>> PS;
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

void solve() {
    string s; cin >> s;
    int n = s.length();
    string r = s;
    reverse(r.begin(), r.end());
    hash61 a(s), b(r);
    vector<vector<int>> cnt(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int ni = n - 1 - j;
            int nj = n - 1 - i;
            if (a(i, j) == b(ni, nj)) cnt[i][j]++;
        }
    }
    int q;
    cin >> q;
    TwoDPrefixSum<int> arr(cnt);
    while (q--) {
        int i, j;
        cin >> i >> j;
        i--, j--;
        cout << arr.submatrixSum(i, i, j, j) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // int N = 5000;
    // for (int i = 0; i < N; i++) {
    //     int r = rng() % 1;
    //     cout << (char)('a' + r);
    // }
    // cout << endl;
    // int Q = 1e6;
    // for (int i = 0; i < Q; i++) {
    //     int r = rng() % N;
    //     cout << r + 1 << " " << N << endl;
    // }
    solve();
}*/





/*

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class fenwick {
public:
    fenwick(int _n, int _m) : n(_n), m(_m) {
        // Resize the tree to n+3 and m+3 for convenient bitwise operations
        cerr << "init " << n << " " << m << endl;
        arr.resize(n + 3, vector<T>(m + 3, 0));
    }

    void add(int x, int y, T val) {
        // Iterate through x and y dimensions using bitwise operations
        for (int i = x; i <= n; i += (i & -i)) {
            for (int j = y; j <= m; j += (j & -j)) {
                arr[i][j] += val;
            }
        }
    }

    T query(int x, int y) {
        T sum = 0;
        // Similar to 1D Fenwick tree, iterate using bitwise operations
        for (int i = x; i > 0; i -= (i & -i)) {
            for (int j = y; j > 0; j -= (j & -j)) {
                sum += arr[i][j];
            }
        }
        return sum;
    }

    // Range query using four quadrant sums for efficient calculation
    T rangeQuery(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }

private:
    int n, m;
    // 2D tree to store prefix sums
    vector<vector<T>> arr;
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

void solve() {
    string s; cin >> s;
    cerr << "s = " << s << endl;
    int n = s.length();
    string r = s;
    reverse(r.begin(), r.end());
    hash61 a(s), b(r);
    fenwick<int> fen(n, n);
    //cerr << "starting" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            //cerr << i << " | " << j << endl;
            int ni = n - 1 - j;
            int nj = n - 1 - i;
            if (a(i, j) == b(ni, nj)) {
                cerr << "good " << i << " " << j << endl;
                fen.add(i + 1, j + 1, 1);
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int i, j;
        cin >> i >> j;
        cout << fen.rangeQuery(i, i, j, j) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}*/