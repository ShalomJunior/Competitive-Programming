#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, n;
    cin >> x >> y >> n;
    int X = 3 * x;
    int q = n / 3;
    int r = n % 3;
    cout << q * min(X, y) + r * x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
