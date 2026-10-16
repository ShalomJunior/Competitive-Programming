#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    bool flag = true;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            cnt += a[i][j];
            if (i && j) {
                int s = a[i - 1][j - 1] + a[i - 1][j] + a[i][j - 1] + a[i][j];
                if (s & 1) {
                    flag = false;
                }
            }
        }
    }
    if (n == 1 || m == 1) {
        cout << n * m - cnt << endl;
        return;
    }
    if (!flag) {
        cout << -1 << endl;
        return;
    }
    vector<int> r(n);
    vector<int> c(m);
    auto f = [&](int  i, int j) {
        return a[i][j] + r[i] + c[j];
        };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (f(i, j) % 2 == 0) {
                if (j + 1 < m && f(i, j + 1) % 2 == 0 && r[i] == 0) {
                    r[i]++;
                }
                else if (i + 1 < n && f(i + 1, j) % 2 == 0 && c[j] == 0) {
                    c[j]++;
                }
                else {
                    if (r[i] == 0) r[i]++;
                    else if (c[j] == 0) c[j]++;
                    else {
                        cout << -1 << endl;
                        return;
                        assert(false);
                    }
                }
            }
        }
    }
    cout << accumulate(r.begin(), r.end(), 0) + accumulate(c.begin(), c.end(), 0) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}