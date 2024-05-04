#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, x, y; cin >> n >> x >> y;
    int ppcm = lcm(x, y);
    int common = n / ppcm;
    int f = n / x - common, s = n / y - common;
    int a = f * (n - f + 1 + n) / 2, b = s * (s + 1) / 2;
    cout << a - b << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}