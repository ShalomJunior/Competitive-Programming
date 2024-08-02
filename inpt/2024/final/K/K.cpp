#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int k, q;
    cin >> k >> q;
    auto up = [&](int& p) {
        int r = p % k;
        p /= k;
        if (r > 1)p++;
        };
    while (q--) {
        int a, b;
        cin >> a >> b;
        int x = 0, y = 0;
        while (a != b) {
            if (a > b) {
                up(a);
                x++;
            }
            else {
                up(b);
                y++;
            }
        }
        if (x == 0 && y == 0)
            cout << 0;
        else if (x == 0 || y == 0)
            cout << max(x, y) + 1;
        else
            cout << x + y + 1;
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}