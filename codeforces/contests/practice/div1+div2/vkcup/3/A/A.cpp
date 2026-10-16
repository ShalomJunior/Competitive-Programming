#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;
void solve() {
    int x, y, p, q;
    cin >> x >> y >> p >> q;
    if (p == 0) {
        cout << (x == 0 ? 0 : -1) << endl;
        return;
    }
    int g = __gcd(p, q);
    p /= g;
    q /= g;
    auto check = [&](int mid) {
        int m = (y + mid) / q;
        int need = p * m - x;
        return need >= 0 && need <= mid;
        };
    int r = (q - y % q) % q;
    int L = 0, R = INF;
    while (L < R) {
        int mid = (L + R) / 2;
        int use = mid * q + r;
        check(use) ? R = mid : L = mid + 1;
    }
    cout << (R == INF ? -1 : R * q + r) << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
