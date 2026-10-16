#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int x1 = (x + k - 1) / k;
    int y1 = (y + k - 1) / k;
    if (x1 > y1) {
        cout << x1 * 2 - 1;
    }
    else {
        cout << y1 * 2;
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
