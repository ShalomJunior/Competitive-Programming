#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        if (i & 1) {
            a[i] = mx;
        }
    }
    int ans = 0;
    for (int i = 0; i + 1 < n; i += 2) {
        if (a[i] == a[i + 1]) {
            ans++;
            a[i]--;
        }
    }
    for (int i = 1; i + 1 < n; i += 2) {
        if (a[i] <= a[i + 1])
            ans += a[i + 1] - a[i] + 1;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
