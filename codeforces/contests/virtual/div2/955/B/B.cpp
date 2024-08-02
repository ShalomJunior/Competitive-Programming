#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    while (x > 1 && k > 0) {
        x++;
        k--;
        int r = x % y;
        if (r > 0) {
            r = y - r;
        }
        int add = min(r, k);
        x += add;
        k -= add;
        while (x % y == 0) x /= y;
    }
    if (k > 0) {
        k %= (y - 1);
        x += k;
    }
    cout << x << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}