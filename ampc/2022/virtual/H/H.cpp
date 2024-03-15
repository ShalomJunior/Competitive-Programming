#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int a, L, l, m; cin >> a >> L >> l >> m;
    int x = 0;
    while (x * a + (x + 1) * m <= L)x++; x--;
    int y = 0;
    while (y * a + (y + 1) * m <= l)y++; y--;
    cout << x * y << endl;
}