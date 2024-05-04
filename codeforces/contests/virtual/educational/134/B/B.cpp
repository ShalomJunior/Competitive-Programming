#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, x, y, d;
    cin >> n >> m >> x >> y >> d;
    int x1 = max(x - d, 1), x2 = min(x + d, n);
    int y1 = max(y - d, 1), y2 = min(y + d, m);
    cout << ((x1 > 1 && y2 < m) || (x2 < n && y1 > 1) ? n + m - 2 : -1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
