#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    int m = 0, M = 0;
    for (int i = 0; i < n; ++i) {
        int c; cin >> c;
        m += c; M += c / x;
        if (c % x) M++;
    }
    cout << m / x + (m % x ? 1 : 0) << " " << M << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}