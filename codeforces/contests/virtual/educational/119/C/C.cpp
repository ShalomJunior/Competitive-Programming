#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    vector<int> lim(n + 1);
    for (int i = 0, s = 0; i < n; i++) {
        s += a[i];
        if (s <= x) {
            lim[i] = 1 + (x - s) / (i + 1);
            lim[i] = max(lim[i], 0LL);
        }
    }
    int ans = 0;
    for (int i = n - 1, k = n; i >= 0; i--, k--) {
        int d = lim[i] - lim[i + 1];
        ans += d * k;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
