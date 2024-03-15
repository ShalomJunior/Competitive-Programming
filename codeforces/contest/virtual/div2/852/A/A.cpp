#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    int x = m * a;
    int y = (m + 1) * b;
    int ans = min(x, y) * (n / (m + 1));
    n %= (m + 1);
    ans += min(a, b) * n;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}