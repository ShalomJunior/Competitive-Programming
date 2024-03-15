#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int x = 0, y = 0;
    x += (c / 2) * 3;
    y += ((c + 1) / 2) * 3;
    if (c % 2 && b) {
        x += 2;
        b--;
    }
    x += ((b + 1) / 2) * 2;
    y += (b / 2) * 2;
    int diff = abs(x - y);
    int delta = min(a, diff);
    a -= delta;
    diff -= delta;
    cout << (a ? a % 2 : diff) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}