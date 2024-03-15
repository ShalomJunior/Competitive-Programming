#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    int gd;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (i) gd = gcd(gd, x);
        else gd = x;
    }
    int ans = 0;
    for (int i = 1; i * i <= gd; i++) {
        if (gd % i) continue;
        ans++;
        if (gd / i != i) ans++;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}