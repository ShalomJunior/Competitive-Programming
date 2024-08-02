#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int x1, y1, z1;
    cin >> x1 >> y1 >> z1;
    int x2, y2, z2;
    cin >> x2 >> y2 >> z2;
    y1 = max(y1 - x2, 0LL);
    z2 = max(z2 - x1, 0LL);
    if (z1 < y2) {
        int d = y2 - z1;
        y1 = max(y1 - d, 0LL);
    }
    else if (z1 > y2) {
        int d = z1 - y2;
        z2 = max(z2 - d, 0LL);
    }
    else {}
    cout << min(z1, y2) * 2 - min(y1, z2) * 2 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}