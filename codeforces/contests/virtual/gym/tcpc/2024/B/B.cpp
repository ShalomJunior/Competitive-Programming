#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> pref[i];
        pref[i] += pref[i - 1];
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y, m;
        cin >> x >> y >> m;
        int ans1 = max(pref[n], x);
        int ans2 = pref[min(m, n)] + y;
        cout << min(ans1, ans2) << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
