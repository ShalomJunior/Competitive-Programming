#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 30;
void solve() {
    int x, y;
    cin >> x >> y;
    int k = 0;
    int rx = 0;
    int ry = 0;
    for (int j = 0; j <= N; j++) {
        int m = 1 << j;
        int vx = (x & m ? 1 : 0);
        int vy = (y & m ? 1 : 0);
        if (rx) {
            if (vx) {
                vx = 0;
            }
            else {
                vx = 1;
                rx = 0;
            }
        }
        if (ry) {
            if (vy) {
                vy = 0;
            }
            else {
                vy = 1;
                ry = 0;
            }
        }
        if (vx && vy) {
            k |= m;
        }
    }
    int X = x + k;
    int Y = y + k;
    if (X + Y == (X ^ Y)) {
        cout << k;
    }
    else {
        cout << -1;
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
