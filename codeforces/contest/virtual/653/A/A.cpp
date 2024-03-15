#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, n;
    cin >> x >> y >> n;
    int q = n / x, r = n % x;
    if (r >= y) cout << q * x + y;
    else cout << (q - 1) * x + y;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}