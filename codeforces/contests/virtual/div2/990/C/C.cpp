#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2;
const int INF = 1e18;
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(N, vector<int>(n));
    int f = 0;
    int g = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (i == 1) a[0][j] > a[1][j] ? f += a[0][j] : g += a[1][j];
        }
    }
    int ans = -INF;
    for (int i = 0; i < n; i++) {
        ans = max(ans, f + g + min(a[0][i], a[1][i]));
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
