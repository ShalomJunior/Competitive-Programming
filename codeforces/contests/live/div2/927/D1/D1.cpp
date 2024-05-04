#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int b = 1; b <= m; b++) {
        for (int a = b; a <= n; a += b) {
            if ((a + b) % (b * __gcd(a, b)) == 0) ans++;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
