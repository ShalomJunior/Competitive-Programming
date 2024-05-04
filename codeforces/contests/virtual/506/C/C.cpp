#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

const int INF = 2e9;
void solve() {
    int n; cin >> n;
    vector<Mine> a(n);
    for (auto& [l, r] : a) cin >> l >> r;
    sort(a.begin(), a.end());
    vector<Mine> pref(n), suff(n);
    int L = 0, R = INF;
    for (int i = 0; i < n; i++) {
        L = max(L, a[i].F);
        R = min(R, a[i].S);
        pref[i] = { L, R };
    }
    L = 0, R = INF;
    for (int i = 0; i < n; i++) {
        L = max(L, a[n - 1 - i].F);
        R = min(R, a[n - 1 - i].S);
        suff[i] = { L, R };
    }
    int ans = 0;
    if (pref[n - 2].F < pref[n - 2].S) {
        ans = max(ans, pref[n - 2].S - pref[n - 2].F);
    }
    if (suff[n - 2].F < suff[n - 2].S) {
        ans = max(ans, suff[n - 2].S - suff[n - 2].F);
    }
    for (int i = 1; i < n - 1; i++) {
        int l1 = pref[i - 1].F, r1 = pref[i - 1].S;
        int l2 = suff[n - 2 - i].F, r2 = suff[n - 2 - i].S;
        int l = max(l1, l2);
        int r = min(r1, r2);
        if (l <= r) ans = max(ans, r - l);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}