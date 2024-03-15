#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    if (n < m) {
        cout << n * min(a, b) << endl;
        return;
    }
    if (a <= b){
        cout << 
    }
    else {
        int x = n * b;
        int q = n / m, r = n % m;
        int y = q * a + (r > q ? (r - q) * min(a, b) : 0);
        cout << min(x, y) << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}