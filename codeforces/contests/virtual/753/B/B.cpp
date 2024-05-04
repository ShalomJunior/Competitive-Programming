#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int x, n; cin >> x >> n;
    int r = n % 4, add = 4 * (n / 4) + 1;
    while (r--) {
        x & 1 ? x += add : x -= add;
        add++;
    }
    cout << x << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}