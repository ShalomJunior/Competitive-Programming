#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int ans[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i][j] = a[i][j];
            bool f = true;
            int mx = 0;
            if (i > 0) {
                f &= (a[i][j] > a[i - 1][j]);
                mx = max(mx, a[i - 1][j]);
            }
            if (i + 1 < n) {
                f &= (a[i][j] > a[i + 1][j]);
                mx = max(mx, a[i + 1][j]);
            }
            if (j > 0) {
                f &= (a[i][j] > a[i][j - 1]);
                mx = max(mx, a[i][j - 1]);
            }
            if (j + 1 < m) {
                f &= (a[i][j] > a[i][j + 1]);
                mx = max(mx, a[i][j + 1]);
            }
            if (f) ans[i][j] = mx;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
