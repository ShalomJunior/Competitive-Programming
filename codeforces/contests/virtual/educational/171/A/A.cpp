#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int len = min(x, y);
    cout << 0 << " " << 0 << " " << len << " " << len << endl;
    cout << 0 << " " << len << " " << len << " " << 0 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
