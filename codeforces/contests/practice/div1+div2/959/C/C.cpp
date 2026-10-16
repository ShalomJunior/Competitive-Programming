#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    vector<int> dp(n + 2);
    for (int i = n; i > 0; i--) {
        auto it = lower_bound(pref.begin(), pref.end(), pref[i - 1] + x + 1);
        if (it != pref.end()) {
            int j = it - pref.begin();
            dp[i] = j - i + dp[j + 1];
        }
        else {
            dp[i] = n + 1 - i;
        }
    }
    cout << accumulate(dp.begin(), dp.end(), 0LL) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
