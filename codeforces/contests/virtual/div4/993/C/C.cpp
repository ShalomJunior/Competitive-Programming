#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m, a, b, c;
    cin >> m >> a >> b >> c;
    int x = min(m, a);
    int y = min(m, b);
    int r = 2 * m - (x + y);
    int ans = x + y + min(r, c);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}