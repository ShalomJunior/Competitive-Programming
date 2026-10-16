#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << n << endl;
        return;
    }
    int ans = 0;
    while (n >= k) {
        int m = k;
        while (m * k <= n) m *= k;
        n -= m;
        ans++;
    }
    cout << ans + n << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}