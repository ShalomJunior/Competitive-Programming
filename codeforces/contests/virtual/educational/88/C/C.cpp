#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 20;
void solve() {
    int h, c, t;
    cin >> h >> c >> t;
    assert(t != c);
    if (h == t) {
        cout << 1;
    }
    else if (h + c == t * 2) {
        cout << 2;
    }
    else {
        auto f = [&](int mid) {
            return mid * h + (mid - 1) * c;
            };
        auto check = [&](int mid) {
            return f(mid) >= t * (mid * 2 - 1);
            };
        int L = 1, R = 1e7;
        while (L < R) {
            int mid = (L + R) / 2;
            if (check(mid)) {
                if (L == mid) check(R) ? L = R : R = L;
                else  L = mid;
            }
            else R = mid - 1;
        }
        auto x1 = abs((long double)f(L) / (L * 2 - 1) - t);
        auto x2 = abs((long double)f(L + 1) / (L * 2 + 1) - t);
        cout << (x1 < x2 ? L * 2 - 1 : L * 2 + 1);
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
