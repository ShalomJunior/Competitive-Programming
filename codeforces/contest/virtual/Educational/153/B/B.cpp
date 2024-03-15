#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
    int q = m / k, r = m % k;
    m -= min(q, ak) * k;
    int e = min(m, a1);
    m -= e;
    int ansq = m / k, ansr = m % k;
    int ans = ansq + ansr;
    if (ansr) {
        if (e + ansr >= k) {
            ans -= ansr;
            ans++;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}