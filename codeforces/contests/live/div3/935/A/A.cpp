#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b % 3 != 0 && b % 3 + c < 3) {
        cout << -1 << endl;
        return;
    }
    int ans = a + (b + c) / 3;
    if ((b + c) % 3)ans++;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
