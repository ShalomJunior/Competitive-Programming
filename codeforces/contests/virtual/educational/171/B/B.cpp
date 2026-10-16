#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> l(n + 2, 1);
    for (int i = 2; i <= n; i += 2) {
        l[i] = abs(a[i] - a[i - 1]);
        l[i] = max(l[i], l[i - 2]);
    }
    vector<int> r(n + 2, 1);
    for (int i = n - 1; i > 0; i -= 2) {
        r[i] = abs(a[i] - a[i + 1]);
        r[i] = max(r[i], r[i + 2]);
    }
    if (n & 1) {
        int ans = INF;
        for (int i = 1; i <= n; i += 2) {
            ans = min(ans, max(l[i - 1], r[i + 1]));
        }
        cout << ans;
    }
    else {
        cout << l[n];
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
