#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;
    int d = r - l;
    int ans = 0;
    int past = 0;
    int p = 1;
    while (l || r) {
        ans += d / p;
        if (d % p >= p - past)ans++;
        past += (l % 10) * p;
        l /= 10; r /= 10; p *= 10;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}