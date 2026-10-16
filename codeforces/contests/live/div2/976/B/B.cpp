#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int k;
    cin >> k;
    auto check = [&](int mid) {
        int q = sqrtl(mid);
        while ((q + 1) * (q + 1) <= mid) q++;
        return mid - q >= k;
        };
    int L = 0, R = 2e18;
    while (L < R) {
        int mid = (L + R) / 2;
        check(mid) ? R = mid : L = mid + 1;
    }
    cout << L << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}