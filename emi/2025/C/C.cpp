#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 31;

uint64_t rng() {
    static mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<uint64_t> distribution(0, numeric_limits<uint64_t>::max());
    return distribution(generator);
}

template<typename T>
const T Or(const T& a, const T& b) {
    return a | b;
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    auto check = [&](int x, int m) {
        for (int j = 0; j <= N; j++) {
            int mask = 1LL << j;
            if ((x & mask) == 0 && (m & mask) == 1) return false;
        }
        return x >= m;
        };
    map<int, int> h;
    sparseTable<int, Or> g(a);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l1 = h[a[i]], l2 = i;
        while (l1 < l2) {
            int mid = (l1 + l2) / 2;
            check(a[i], g.query(mid, i)) ? l2 = mid : l1 = mid + 1;
        }
        int r1 = i, r2 = n - 1;
        while (r1 < r2) {
            int mid = (r1 + r2) / 2;
            if (check(a[i], g.query(i, mid))) {
                if (r1 == mid) {
                    check(a[i], g.query(i, r2)) ? r1 = r2 : r2 = r1;
                }
                else r1 = mid;
            }
            else r2 = mid - 1;
        }
        assert(l1 == l2);
        assert(r1 == r2);
        int l = i - l1;
        int r = r1 - i;
        ans += l * r + l + r + 1;
        h[a[i]] = i + 1;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}