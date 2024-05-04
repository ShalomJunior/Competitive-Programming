#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int a, b, d; cin >> a >> b >> d;
    if (min(__builtin_ctzll(a), __builtin_ctzll(b)) < __builtin_ctzll(d)) {
        cout << -1 << endl;
        return;
    }
    cout << ((1LL << 30) - 1) * d << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}