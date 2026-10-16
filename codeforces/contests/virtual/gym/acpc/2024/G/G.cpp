#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int xmin, xmax, ymin, ymax;
    cin >> xmin >> xmax >> ymin >> ymax;
    int q;
    cin >> q;
    while (q--) {
        int xa, ya, za;
        cin >> xa >> ya >> za;
        int xb, yb, zb;
        cin >> xb >> yb >> zb;
        int dx = xb - xa;
        int dy = yb - ya;
        int xc = xa + 2 * dx;
        int yc = ya + 2 * dy;
        if (xmin <= xc && xc <= xmax && ymin <= yc && yc <= ymax) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}