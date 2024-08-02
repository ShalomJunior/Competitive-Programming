#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<int> pref(n + 1);
    multiset<int> ms;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        if (i < n) ms.insert(pref[i]);
    }
    int ans = k * pref[n];
    while (k > 1) {
        ans -= *ms.begin();
        ms.erase(ms.begin());
        k--;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
