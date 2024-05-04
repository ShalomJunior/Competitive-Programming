#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int r, b, d;
    cin >> r >> b >> d;
    if (r < b) swap(r, b);
    if (d == 0) {
        cout << (r == b ? "YES" : "NO");
    }
    else {
        cout << (b * (d + 1) < r ? "NO" : "YES");
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
