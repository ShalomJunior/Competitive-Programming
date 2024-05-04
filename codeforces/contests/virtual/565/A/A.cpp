#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    int a = 0, b = 0, c = 0;
    while (n % 2 == 0) { n /= 2; a++; }
    while (n % 3 == 0) { n /= 3; b++; }
    while (n % 5 == 0) { n /= 5; c++; }
    if (n != 1) {
        cout << -1 << endl;
        return;
    }
    cout << a + 2 * b + 3 * c << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}