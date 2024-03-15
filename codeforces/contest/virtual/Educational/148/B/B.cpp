#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n);
    int tot = 0;
    for (auto& c : a) {
        cin >> c;
        tot += c;
    }

    sort(a.begin(), a.end());

    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) pref[1 + i / 2] += a[i];

    for (int i = 0; i < n; i++)
        if (i) pref[i] += pref[i - 1];

    vector<int> suf(n + 1);
    for (int i = n - 1; i >= 0; i--) suf[n - i] += suf[n - i - 1] + a[i];

    int ans = 0;
    for (int i = 0; i <= k; i++)
        ans = max(ans, tot - pref[i] - suf[k - i]);

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}

