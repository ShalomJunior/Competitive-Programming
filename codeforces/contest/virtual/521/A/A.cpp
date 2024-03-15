#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int a, b, k; cin >> a >> b >> k;
    int ans = (a - b) * (k / 2);
    if (k & 1) ans += a;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}