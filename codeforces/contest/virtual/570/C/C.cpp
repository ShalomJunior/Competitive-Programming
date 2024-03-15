#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int k, n, a, b;
    cin >> k >> n >> a >> b;
    if (b * n >= k) {
        cout << -1 << endl;
        return;
    }
    auto go = [&](int mid) {
        int op = n - mid;
        return k > mid * a + op * b;
        };
    int L = 0, R = n;
    while (L < R) {
        int mid = (L + R) / 2;
        bool b = go(mid);
        if (b) {
            if (mid == L) {
                go(R) ? L = R : R = L;
            }
            else L = mid;
        }
        else R = mid - 1;
    }
    cout << L << endl;
}

signed  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}