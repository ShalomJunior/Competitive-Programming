#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k, g; cin >> n >> k >> g;
    int c = (n - 1) * ((g - 1) / 2);
    int r = k * g - c;
    int ans = 0;
    if (r > 0) {
        ans = c;
        r %= g;
        if (2 * r < g) ans += r;
        else ans -= (g - r);
    }
    else ans = k * g;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}