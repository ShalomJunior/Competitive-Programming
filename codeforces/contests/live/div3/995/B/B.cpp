#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int tot = a + b + c;
    int r = n / tot;
    n %= tot;
    int ans = r * 3;
    for (auto& c : { a, b, c }) {
        if (n >= c || n) {
            n -= c;
            ans++;
            n = max(n, 0LL);
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
