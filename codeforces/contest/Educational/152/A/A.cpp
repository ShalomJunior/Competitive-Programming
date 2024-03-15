#include <bits/stdc++.h>
using namespace std;

void solve() {
    int b, c, h; cin >> b >> c >> h;
    int j = c + h;
    if (b > j) cout << 2 * j + 1 << endl;
    else cout << 2 * b - 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}