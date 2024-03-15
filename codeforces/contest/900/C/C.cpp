#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k, x; cin >> n >> k >> x;
    int mn, mx;
    if (n < k) mn = mx = n * (n + 1) / 2;
    else {
        mn = k * (k + 1) / 2;
        mx = k * (n - k + 1 + n) / 2;
    }
    if (mn <= x && x <= mx) cout << "YES";
    else cout << "NO";
    cout << endl;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
