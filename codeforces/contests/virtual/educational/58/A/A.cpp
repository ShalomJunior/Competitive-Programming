#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int l, r, d;
    cin >> l >> r >> d;
    if (d < l) {
        cout << d;
    }
    else {
        cout << r - r % d + d;
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
