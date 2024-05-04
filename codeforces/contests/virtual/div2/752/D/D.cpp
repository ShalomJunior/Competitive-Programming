#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y; cin >> x >> y;
    if (y < x) cout << x + y;
    else {
        int q = y / x, r = y % x;
        cout << 1LL * q * x + r / 2;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}