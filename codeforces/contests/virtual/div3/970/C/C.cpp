#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;
    int len = r - l;
    int q = sqrt(len * 2);
    while (q * (q + 1) / 2 > len) q--;
    while ((q + 1) * (q + 2) / 2 <= len) q++;
    cout << q + 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}