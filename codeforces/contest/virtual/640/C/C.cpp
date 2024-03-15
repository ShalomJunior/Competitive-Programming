#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    int q = k / (n - 1);
    int r = k % (n - 1);
    int ans = q * n + r;
    if (!r) ans--;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}