#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int l, r, k;
    cin >> l >> r >> k;
    int q = r / k;
    while ((q + 1) * k <= r) q++;
    cout << max(q - l + 1, 0LL) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
