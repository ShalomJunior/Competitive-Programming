#include <bits/stdc++.h>
#define int long long
using namespace std;

template<typename T>
class fenwick {
public:
    int n, m;
    vector<vector<T>> tree;
    fenwick(int _n, int _m) : n(_n), m(_m) {
        tree.resize(n + 3, vector<T>(m + 3, 0));
    }

    void update(int x, int y, T val) {
        for (int i = x; i <= n; i += (i & -i)) {
            for (int j = y; j <= m; j += (j & -j)) {
                tree[i][j] += val;
            }
        }
    }

    T query(int x, int y) {
        T sum = 0;
        for (int i = x; i > 0; i -= (i & -i)) {
            for (int j = y; j > 0; j -= (j & -j)) {
                sum += tree[i][j];
            }
        }
        return sum;
    }

    T rangeQuery(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }

};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int f[n][m];
    int diff = 0;
    fenwick<int> fen(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            f[i][j] = c - '0';
            fen.update(i + 1, j + 1, f[i][j] ? -1 : 1);
            if (f[i][j]) {
                a[i][j] *= -1;
            }
            diff += a[i][j];
        }
    }
    int g = 0;
    for (int i = 0; i + k - 1 < n; i++) {
        for (int j = 0; j + k - 1 < m; j++) {
            int s = fen.rangeQuery(i + 1, j + 1, i + k, j + k);
            g = gcd(g, abs(s));
        }
    }
    if (diff == 0) {
        cout << "YES" << endl;
        return;
    }
    if (g) {
        cout << (diff % g ? "NO" : "YES") << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
