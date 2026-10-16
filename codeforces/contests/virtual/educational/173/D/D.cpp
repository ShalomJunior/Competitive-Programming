#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e5;
void solve() {
    int l, r, g;
    cin >> l >> r >> g;
    int x = l / g;
    while (x * g < l) x++;
    int y = r / g;
    int k = N;
    while (__gcd(x, y) != 1 && k--) y--;
    if (y * g < l) {
        cout << -1 << " " << -1 << endl;
        return;
    }
    cout << x * g << " " << y * g << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
