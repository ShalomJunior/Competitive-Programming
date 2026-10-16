#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int a[n][m];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = (c == '.' ? 1 : 0);
            cnt += a[i][j];
        }
    }
    if (x <= y) {
        cout << cnt * x << endl;
        return;
    }
    int tot = 0;
    for (int i = 0; i < n; i++) {
        cnt = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j]) cnt++;
            if (!a[i][j] || j == m - 1) {
                tot += (cnt / 2) * y;
                tot += (cnt % 2) * x;
                cnt = 0;
            }
        }
    }
    cout << tot << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
