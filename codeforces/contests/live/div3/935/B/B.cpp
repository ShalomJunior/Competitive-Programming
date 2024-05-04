#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int a, b, m;
    cin >> a >> b >> m;
    int ans = 2 + m / a + m / b;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
