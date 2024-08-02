#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i].first;
    for (int i = 1; i <= n; i++) cin >> a[i].second;
    sort(a.begin() + 1, a.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
        });
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        int d = a[i].second - a[i].first;
        pref[i] = pref[i - 1] + max(d, 0LL);
    }
    auto query = [&](int l, int r) {
        return pref[r] - pref[l - 1];
        };
    multiset<int> ms;
    vector<int> sum(n + 1);
    for (int i = 1, s = 0; i <= n; i++) {
        s += a[i].first;
        ms.insert(a[i].first);
        while ((int)ms.size() > k) {
            s -= *prev(ms.end());
            ms.erase(prev(ms.end()));
        }
        sum[i] = s;
    }
    int ans = 0;
    for (int i = k; i <= n; i++) {
        int x = (i == n ? 0 : query(i + 1, n));
        ans = max(ans, x - sum[i]);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
