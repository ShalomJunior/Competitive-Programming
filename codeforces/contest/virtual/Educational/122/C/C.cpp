#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int hc, dc, hm, dm, k, w, a;
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;
    for (int i = 0; i <= k; i++) {
        int new_hc = hc + i * a;
        int new_dc = dc + (k - i) * w;
        int tc = (hm / new_dc) + (hm % new_dc ? 1 : 0);
        int tm = (new_hc / dm) + (new_hc % dm ? 1 : 0);
        if (tc <= tm) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
