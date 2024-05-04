#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), pref(n);
    for (int i = 0, sum = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        pref[i] = sum;
    }
    vector<int> fit(n);
    for (int i = n - 2; i >= 0; i--) {
        int r = k - a[i];
        auto it = upper_bound(pref.begin(), pref.end(), pref[i] + r);
        fit[i] = it - (pref.begin() + i);
    }
    vector<int> dp(n);
    for (int i = n - 1; i >= 0; i--) {
        int j = i + fit[i];
        dp[i] = 1 + (j < n ? dp[j] : 0);
    }
    int ans;
    for (int i = 0; i < n; i++) {
        if (dp[i] <= m) {
            ans = n - i;
            break;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}