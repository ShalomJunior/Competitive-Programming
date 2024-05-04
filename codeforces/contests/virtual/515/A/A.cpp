#include <bits/stdc++.h>
using namespace std;

void solve() {
    int L, v, l, r;
    cin >> L >> v >> l >> r;
    int cnt = L / v;
    int mn = (l % v ? l - l % v + v : l);
    int mx = (r % v ? r - r % v : r);
    if (mn <= mx) {
        int d = 1 + (mx - mn) / v;
        cnt -= d;
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}