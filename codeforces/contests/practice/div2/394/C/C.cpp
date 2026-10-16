#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;
    if (n == 1) {
        int r = k % m;
        int ans = k / m + (r >= y ? 1 : 0);
        cout << (k + m - 1) / m << " " << k / m << " " << ans << endl;
        return;
    }
    int q = 2 * (n - 1) * m;
    int mx = 2 * (k / q);
    int r = k % q;
    if (r > n * m) mx += 2;
    else if (r > m) mx += 1;
    else;
    int mn = 2 * (k / q) + (r == 0 ? -1 : 0);
    int ans = 2 * (k / q);
    if (x == 1) {
        if (r < y) ans--;
    }
    else {

    }
    cout << mx << " " << mn << " " << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
