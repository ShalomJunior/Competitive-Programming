#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int c, m, x;
    cin >> c >> m >> x;
    auto check = [&](int mid) {
        return c + m + x >= mid * 3;
        };
    int L = 0, R = min(c, m);
    while (L < R) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            if (L == mid) check(R) ? L = R : R = L;
            else L = mid;
        }
        else R = mid - 1;
    }
    cout << R << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
