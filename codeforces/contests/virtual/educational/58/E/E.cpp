#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int q;
    cin >> q;
    int X = 0, Y = 0;
    while (q--) {
        char c;
        cin >> c;
        if (c == '+') {
            int x, y;
            cin >> x >> y;
            if (x < y) swap(x, y);
            X = max(X, x);
            Y = max(Y, y);
        }
        else {
            int h, w;
            cin >> h >> w;
            if (h < w) swap(h, w);
            cout << (X <= h && Y <= w ? "YES" : "NO") << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
