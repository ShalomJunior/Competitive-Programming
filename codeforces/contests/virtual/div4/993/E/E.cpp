#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e12;
void solve() {
    int k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    int q = 1;
    int ans = 0;
    while (q <= INF) {
        int mn = l2 / q;
        int mx = r2 / q;
        while (mn * q < l2) mn++;
        while (mx * q > r2) mx--;
        int L = max(mn, l1);
        int R = min(mx, r1);
        if (L <= R) ans += R - L + 1;
        q *= k;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}