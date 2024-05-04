#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    if (n < 3) { cout << 1 << endl;return; }
    cout << 1 + ceil(static_cast<double>(n - 2) / x) << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}