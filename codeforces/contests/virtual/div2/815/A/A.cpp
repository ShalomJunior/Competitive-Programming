#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = a * d;
    int y = b * c;
    if (x == y)
        cout << 0;
    else if (x == 0 || y == 0 || x % y == 0 || y % x == 0)
        cout << 1;
    else
        cout << 2;
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}