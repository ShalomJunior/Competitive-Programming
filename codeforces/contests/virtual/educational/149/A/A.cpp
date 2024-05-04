#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, k; cin >> x >> k;
    if (x % k != 0) { cout << 1 << endl << x << endl; }
    else { cout << 2 << endl << x - 1 << " " << 1 << endl; }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}

