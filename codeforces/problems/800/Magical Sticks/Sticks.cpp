#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    (n & 1) ? cout << 1 + n / 2 << endl : cout << n / 2 << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}