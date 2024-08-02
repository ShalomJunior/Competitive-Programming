#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    int ans = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            int m = k / (i * j);
            if (i * j * m == k && m <= z) {
                int ways = (x - i + 1) * (y - j + 1) * (z - m + 1);
                ans = max(ans, ways);
            }
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
