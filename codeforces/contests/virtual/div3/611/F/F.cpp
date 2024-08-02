#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), d(m), f(k);
    for (auto& c : a) cin >> c;
    for (auto& c : d) cin >> c;
    for (auto& c : f) cin >> c;
    sort(d.begin(), d.end());
    sort(f.begin(), f.end());
    int mx = 0;
    map<int, int> h;
    for (int i = 1; i < n; i++) {
        int len = a[i] - a[i - 1];
        h[len]++;
        mx = max(mx, len);
    }
    if (h[mx] > 1) {
        cout << mx << endl;
        return;
    }
    int L = -1, R = mx;
    int l, r;
    for (int i = 1; i < n; i++) {
        int len = a[i] - a[i - 1];
        if (len == mx) {
            l = a[i - 1];
            r = a[i];
        }
        else L = max(L, len);
    }
    if (L == -1) L = (mx + 1) / 2;
    auto go = [&](int mid) {
        if (mx > 2 * mid) return false;
        int x = r - mid, y = l + mid;
        for (int i = 0; i < m; i++) {
            int nx = max(x - d[i], 0LL);
            int ny = max(y - d[i], 0LL);
            auto it1 = lower_bound(f.begin(), f.end(), nx);
            auto it2 = upper_bound(f.begin(), f.end(), ny);
            if (it2 == f.begin())continue;
            --it2;
            if (it1 <= it2)return true;
        }
        return false;
        };
    while (L < R) {
        int mid = (L + R) / 2;
        go(mid) ? R = mid : L = mid + 1;
    }
    cout << L << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}