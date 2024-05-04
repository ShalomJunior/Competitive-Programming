#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int v[m][2], h[n][2];
    memset(v, 0, sizeof(v));
    memset(h, 0, sizeof(h));
    vector<int> v(m), h(n);
    char ans[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'U') {
                char c = (h[i][0] <= h[i][1] ? 'W' : 'B');
                ans[i][j] = c;
                int k = (c == 'W' ? 0 : 1);
                h[i][k]++;
                v[j][k]++;
                c = (c == 'W' ? 'B' : 'W');
                h[i + 1][(k + 1) % 2]++;
                v[j][(k + 1) % 2]++;
                ans[i + 1][j] = c;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 'L') {
                char c = (v[j][0] <= v[j][1] ? 'W' : 'B');
                ans[i][j] = c;
                int k = (c == 'W' ? 0 : 1);
                v[j][]
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}