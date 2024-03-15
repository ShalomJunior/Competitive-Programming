#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n; cin >> n;

    if (n & 1) cout << (4 * n) / gcd(4 * n, n + 1) + 1 << endl;
    else cout << 4 * n + 1 << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}