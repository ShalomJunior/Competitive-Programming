#include <bits/stdc++.h>
#define int long long
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), h(n);
    for (auto& c : a) cin >> c;
    for (auto& c : h) cin >> c;
    vector<Mine> seg;
    int start = 0;
    for (int i = 1; i < n; i++) {
        if (h[i - 1] % h[i] > 0) {
            seg.push_back({ start, i - 1 });
            start = i;
            if (i == n - 1) seg.push_back({ n - 1, n - 1 });
            continue;
        }
        if (i == n - 1)
            seg.push_back({ start, i });
    }
    if (n == 1) seg.push_back({ 0, 0 });
    vector<int> pref(n);
    for (int i = 0; i < n; i++) {
        pref[i] = a[i] + (i ? pref[i - 1] : 0);
    }
    int ans = 0;
    for (auto& [l, r] : seg) {
        for (int i = l; i <= r; i++) {
            auto it = upper_bound(pref.begin(), pref.end(), (k + (i ? pref[i - 1] : 0LL)));
            --it;
            int j = it - pref.begin();
            j = min(j, r);
            ans = max(ans, j - i + 1);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
