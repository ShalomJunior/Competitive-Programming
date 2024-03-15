#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 2e9;
void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n);
    int sum = 0, m = INF;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; j++) cin >> a[i][j];
        sort(a[i].begin(), a[i].end());
        sum += a[i][1];
        m = min(m, a[i][0]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, sum - a[i][1] + m);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}