#include <bits/stdc++.h>
using namespace std;

void erase(multiset<int>& ms, int x) { ms.erase(ms.find(x)); }

void solve() {
    int n, d; cin >> n >> d;
    vector<int> a(n), free(n + 1);
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        free[i] = a[i] - 1 - (i ? a[i - 1] : 0);
        if (i == n - 1) free[n] = d - a[i];
        ms.insert(free[i]);
    }
    int ans = *ms.begin();
    for (int i = 0; i < n - 1; i++) {
        erase(ms, free[i]);
        if (i < n - 1) erase(ms, free[i + 1]);
        ms.insert(free[i] + free[i + 1] + 1);
        int large = *prev(ms.end());
        if (free[n] - 1 > (large - 1) / 2) {
            ms.insert(free[n] - 1);
            ans = max(ans, *ms.begin());
            erase(ms, free[n] - 1);
        }
        else {
            erase(ms, large); ms.insert((large - 1) / 2);
            ans = max(ans, *ms.begin());
            erase(ms, (large - 1) / 2); ms.insert(large);
        }
        erase(ms, free[i] + free[i + 1] + 1);
        ms.insert(free[i]); ms.insert(free[i + 1]);
    }
    erase(ms, free[n - 1]);
    int space = free[n - 1] + free[n];
    ms.insert(space);
    ans = max(ans, *ms.begin());
    erase(ms, space);
    if (!ms.empty()) {
        int mx = *prev(ms.end());
        if ((mx - 1) / 2 > space) {
            erase(ms, mx); ms.insert((mx - 1) / 2);
            ans = max(ans, *ms.begin());
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}