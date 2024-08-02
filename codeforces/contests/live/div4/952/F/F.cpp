#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int h, n;
    cin >> h >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    auto check = [&](int mid) {
        __int128_t tot = 0;
        for (int i = 0; i < n; i++) {
            tot += a[i] * ((__int128_t)(mid + b[i] - 1) / b[i]);
        }
        return tot >= h;
        };
    int L = 1, R = 1e12;
    while (L < R) {
        int mid = (L + R) / 2;
        check(mid) ? R = mid : L = mid + 1;
    }
    cout << R << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
