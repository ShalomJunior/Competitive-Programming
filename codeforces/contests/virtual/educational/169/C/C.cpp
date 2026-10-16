#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.rbegin(), a.rend());
    for (int i = 1; i < n; i += 2) {
        int add = a[i - 1] - a[i];
        int can = min(add, k);
        a[i] += can;
        k -= can;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        i & 1 ? ans -= a[i] : ans += a[i];
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
