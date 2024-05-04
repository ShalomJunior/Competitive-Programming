#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

template<typename T>
const T Min(const T& a, const T& b) {
    return min(a, b);
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
    int n, s;
    cin >> n >> s;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    sparseTable<int, Min> g(pre);
    auto go = [&](int i, int mid) {
        int mn = g.query(i, i + mid - 1);
        int delta = max(pre[i - 1] - mn, 0LL);
        return delta <= s;
        };
    int cnt = 0;
    int j = -1;
    for (int i = 1; i <= n; i++) {
        int L = 1, R = n - i + 1;
        while (L < R) {
            int mid = (L + R) / 2;
            if (go(i, mid)) {
                if (L == mid) go(i, R) ? L = R : R = L;
                else L = mid;
            }
            else R = mid - 1;
        }
        if (L == R && go(i, L) && cnt < L) {
            cnt = L;
            j = i;
        }
    }
    if (cnt) {
        cout << j << " " << j + cnt - 1;
    }
    else cout << -1;
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}