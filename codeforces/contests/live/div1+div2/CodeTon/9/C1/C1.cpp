#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int x, m;
    cin >> x >> m;
    int j = 1;
    while (j * 2 <= x) j *= 2;
    int L = j;
    int R = j * 2;
    int ans = 0;
    for (int y = L; y <= m && y < R; y++) {
        int v = x ^ y;
        if (v) {
            if (x % v == 0 || y % v == 0) ans++;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}