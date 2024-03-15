#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i * i <= 2 * n; ++i) {
        int x = i * i;
        if (x > 1 && x & 1) ans++;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}