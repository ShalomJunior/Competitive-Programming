#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
struct info {
    int v;
    int i;
    int j;
    bool operator<(const info& other) const {
        return (v < other.v);
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<info> D;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            D.push_back({ a[i][j], i, j });
        }
    }
    sort(D.begin(), D.end());
    int z = D.size();
    int moves = 0;
    for (int k = 0; k < z; k++) {
        auto& [v, i, j] = D[k];
        bool f = true;
        int mn = -1;
        for (int di : { -1, 1 }) {
            int ni = i + di;
            if (0 <= ni && ni < n) {
                if (a[ni][j] <= v) v = max(v, a[ni][j]);
                mn = min(mn, a[ni][j]);
                f &= a[ni][j] != v;
            }
        }
        for (int dj : { -1, 1 }) {
            int nj = j + dj;
            if (0 <= nj && nj < m) {
                if (a[i][nj] <= v) v = max(v, a[i][nj]);
                f &= a[i][nj] != v;
            }
        }
        if (mn > v) mn = -1;
        if (f) moves += v - mn - 1;
        a[i][j] = mn + 1;
    }
    cout << (moves & 1 ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
