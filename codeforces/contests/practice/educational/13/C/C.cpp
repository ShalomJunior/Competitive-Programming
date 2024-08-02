#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    int ans = (n / a) * p + (n / b) * q;
    ans -= (n / lcm(a, b)) * min(p, q);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
