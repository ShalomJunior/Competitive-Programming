#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b; cin >> a >> b;

    if (a == b) { cout << 0 << endl; return; }

    if (a < b && (b - a) & 1 || a > b && !((a - b) & 1)) cout << 1 << endl;
    else cout << 2 << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}