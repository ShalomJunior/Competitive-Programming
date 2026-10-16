#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    int ans = 1;
    int g = a[0] * b[0];
    int l = b[0];
    for (int i = 0; i < n; i++) {
        int ng = gcd(g, a[i] * b[i]);
        int nl = lcm(l, b[i]);
        if (ng % nl) {
            ans++;
            g = a[i] * b[i];
            l = b[i];
        }
        else {
            g = ng;
            l = nl;
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
