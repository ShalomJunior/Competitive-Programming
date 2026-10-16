#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;
    if (n == 1) {
        int r = k % m;
        cout << k / m + (r ? 1 : 0) << " ";
        cout << k / m << " ";
        cout << k / m + (r >= y ? 1 : 0);
    }
    else if (n == 2) {
        int q = 2 * m;
        int r = k % q;
        cout << k / q + (r ? 1 : 0) << " ";
        cout << k / q << " ";
        if (x == 1) {
            cout << k / q + (r >= y ? 1 : 0) << " ";
        }
        else {
            cout << k / q + (r >= m + y ? 1 : 0) << " ";
        }
    }
    else {
        int q = 2 * (n - 1) * m;
        int rounds = k / q;
        int r = k % q;
        cout << max(2 * rounds + (r > n * m ? 2 : r > m ? 1 : 0), 1LL) << " ";
        cout << rounds + (r >= n * m ? 1 : 0) << " ";
        if (x == 1) {
            cout << rounds + (r >= y ? 1 : 0) << " ";
        }
        else if (x == n) {
            cout << rounds + (r >= (n - 1) * m + y ? 1 : 0) << " ";
        }
        else {
            cout << 2 * rounds + (r >= (n + n - x - 1) * m + y ? 2 : r >= (x - 1) * m + y ? 1 : 0) << " ";
        }
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
