#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    map<pair<int, int>, int> h;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int rx = a[i] % x;
        int ry = a[i] % y;
        ans += h[{(x - rx) % x, ry}];
        h[{rx, ry}]++;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}