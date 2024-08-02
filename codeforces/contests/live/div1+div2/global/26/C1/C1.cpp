#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int curr = abs(pref[i]) + pref[n] - pref[i];
        ans = max(ans, curr);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}