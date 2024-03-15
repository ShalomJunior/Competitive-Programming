#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    double a, b; cin >> a >> b;
    int ans = 1e18;
    for (int i = 1; i < 1e5; i++) {
        ans = min(ans, i - 1 + (int)(ceil(a / i) + ceil(b / i)));
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}