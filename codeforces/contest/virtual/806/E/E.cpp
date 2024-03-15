#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int a[n][n];
    bool vis[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            a[i][j] = c - '0';
            vis[i][j] = false;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j]) continue;
            int z = 0, o = 0;
            a[i][j] ? o++ : z++;
            a[j][n - 1 - i] ? o++ : z++;
            a[n - 1 - i][n - 1 - j] ? o++ : z++;
            a[n - 1 - j][i] ? o++ : z++;
            vis[i][j] = vis[j][n - 1 - i] = vis[n - 1 - i][n - 1 - j] = vis[n - 1 - j][i] = true;
            ans += min(o, z);
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}