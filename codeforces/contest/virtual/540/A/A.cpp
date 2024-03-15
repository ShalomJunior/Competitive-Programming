#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (2 * a > b) {
        int ans = b * (n / 2);
        if (n & 1) ans += a;
        cout << ans << endl;
    }
    else cout << n * a << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}