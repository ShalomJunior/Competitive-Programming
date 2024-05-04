#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, k; cin >> x >> y >> k;
    if (y <= x) cout << x;
    else {
        if (x + k >= y) cout << y;
        else cout << y + y - (x + k);
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
