#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int l = 0, r = n;
    auto go = [&](int t) {
        int mn = INF;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) continue;
            int end = i + a[i] * t;
            mn = min(mn, end);
            mx = max(mx, end);
        }
        return mx - mn + 1;
        };
    int ans = n;
    while (l + 1 < r) {
        int len = r - l + 1;
        int x = l + len / 3;
        int y = r - len / 3;
        int gx = go(x);
        int gy = go(y);
        if (gx <= gy) {
            r = y;
            ans = min(ans, gx);
        }
        else {
            l = x;
            ans = min(ans, gy);
        }
    }
    for (int t = l; t <= r; t++) {
        ans = min(ans, go(t));
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}