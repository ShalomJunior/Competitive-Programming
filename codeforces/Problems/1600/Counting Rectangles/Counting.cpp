#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1005;
int rec[N][N], dp[N][N];
void solve() {
    int n, q; cin >> n >> q;
    memset(rec, 0, sizeof(rec));
    for (int i = 0; i < n; i++) {
        int h, w; cin >> h >> w;
        rec[h][w]++;
    }
    memset(dp, 0, sizeof(dp));
    for (int h = 1; h < N; h++) {
        for (int w = 1; w < N; w++) {
            dp[h][w] = dp[h - 1][w] + dp[h][w - 1] - dp[h - 1][w - 1] + rec[h][w] * h * w;
        }
    }
    while (q--) {
        int hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        hb--, wb--;
        int ans = 0;
        if (hs <= hb && ws <= wb) {
            ans = dp[hb][wb] + dp[hs][ws] - dp[hb][ws] - dp[hs][wb];
        }
        cout << ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}