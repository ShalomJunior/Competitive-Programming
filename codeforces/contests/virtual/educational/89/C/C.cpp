#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    map<int, map<int, int>> h;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            int d = i + j;
            h[min(d, n + m - 2 - d)][a[i][j]]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n + m - 2; i++) {
        ans += min(h[i][0], h[i][1]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
