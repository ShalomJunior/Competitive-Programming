#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<int> pref(n + 1);
    vector<int> suf(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + a[i];
    }
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<int> best(n + 1);
    for (int i = 1; i <= n; i++) {
        best[i] = max(best[i - 1], 0LL) + a[i];
    }
    vector<int> pmx(n + 2, -INF);
    for (int i = n; i >= 1; i--) {
        pmx[i] = max(pmx[i + 1], pref[i]);
    }
    vector<int> smx(n + 2, -INF);
    for (int i = 1; i <= n; i++) {
        smx[i] = max(smx[i - 1], suf[i]);
    }
    int ans = *max_element(best.begin() + 1, best.end());
    if (k & 1) {
        for (int i = 1; i <= n; i++) {
            int l = i == 1 ? 0 : smx[i - 1] - suf[i];
            int r = i == n ? 0 : pmx[i + 1] - pref[i];
            l = max(l, 0LL);
            r = max(r, 0LL);
            ans = max(ans, l + a[i] + b[i] + r);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
