#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (auto& [f, _] : a) cin >> f;
    for (auto& [_, s] : a) cin >> s;
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto [k, v] = a[i];
        int x = m / k;
        x = min(x, v);
        int r = m - x * k;
        int y = 0;
        int ex = 0;
        if (i + 1 < n && a[i + 1].first == k + 1) {
            y = r / (k + 1);
            y = min(y, a[i + 1].second);
            r -= y * (k + 1);
            ex = min({ x, r, a[i + 1].second - y });
        }
        x -= ex;
        y += ex;
        ans = max(ans, x * k + y * (k + 1));
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
