#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int x = a[0], y = a[1];
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) x = gcd(x, a[i]);
        else y = gcd(y, a[i]);
    }
    bool ans1 = false, ans2 = false;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) ans1 |= (a[i] % y == 0);
        else ans2 |= (a[i] % x == 0);
    }
    if (!ans1) cout << y;
    else if (!ans2) cout << x;
    else cout << 0;
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}