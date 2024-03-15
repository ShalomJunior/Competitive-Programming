#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    int q = sqrt(2 * n);
    if (q * (q + 1) <= 2 * n) q++;
    cout << q + (n - q * (q - 1) / 2) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}