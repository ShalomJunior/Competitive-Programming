#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e4;
void solve() {
    int x, m;
    cin >> x >> m;
    if (x == 1) {
        cout << m << endl;
        return;
    }
    int j = 1;
    while (j * 2 <= x) j *= 2;
    int ans = 0;
    for (int y = 1; y <= m && y < j * 2; y++) {
        int v = x ^ y;
        if (v % x == 0 || v % y == 0) {
            ans++;
        }
    }
    int q = m / x;
    for (int i = 0; i <= N; i++) {
        int k = m - i;
        int X = x ^ k;
        if (X % x == 0) q = max(q, X / x);
    }
    int mine = ans + q - 1;
    for (int k = q - 1; k > 1 && k > q - 4; k--) {
        int X = k * x;
        int y = X ^ x;
        if (y > m) mine--;
    }
    cout << mine << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}