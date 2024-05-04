#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    sort(a.begin(), a.end());
    int g = a[n - 1] - a[0];
    for (int i = 0; i < n; i++) {
        if (a[n - 1] - a[i] > 0) {
            g = gcd(g, a[n - 1] - a[i]);
        }
    }
    int up = 0;
    for (int i = 0; i < n; i++) {
        up += (a[n - 1] - a[i]) / g;
    }
    set<int> s(a.begin(), a.end());
    for (int i = 0; a[n - 1] - g * i > a[0]; i++) {
        if (!s.count(a[n - 1] - g * i)) {
            cout << up + i << endl;
            return;
        }
    }
    cout << up + min(n, 1 + (a[n - 1] - a[0]) / g) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
