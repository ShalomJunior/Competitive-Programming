#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][m] += a[i][j];
        }
    }
    sort(a.begin(), a.end(), [&](const vector<int>& f, const vector<int>& g) {
        return f.back() > g.back();
        });
    vector<int> c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c.push_back(a[i][j]);
        }
    }
    int k = n * m;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += (k - i) * c[i];
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
