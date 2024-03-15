#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) a[i][j] = s[j];
    }
    int vis[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            vis[i][j] = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j]) continue;
            vector<char> v;
            v.push_back(a[i][j]);
            v.push_back(a[j][n - 1 - i]);
            v.push_back(a[n - 1 - i][n - 1 - j]);
            v.push_back(a[n - 1 - j][i]);
            vis[i][j] = vis[j][n - 1 - i] = vis[n - 1 - i][n - 1 - j] = vis[n - 1 - j][i] = 1;
            sort(v.begin(), v.end());
            int m = v.size();
            for (int k = 0; k < m; k++) {
                ans += v[m - 1] - v[k];
            }
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
