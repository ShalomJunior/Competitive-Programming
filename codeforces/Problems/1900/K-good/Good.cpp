#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    if (n & 1) { cout << 2 << endl; return; }
    while (n % 2 == 0)n /= 2;
    cout << ((n == 1) ? -1 : n) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}