#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, x, y; cin >> n >> x >> y;
    string a, b; cin >> a >> b;
    vector<int> bad;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) bad.push_back(i);
    }
    int m = bad.size();
    if (m & 1) {
        cout << -1 << endl;
        return;
    }
    if (x >= y) {
        if (m == 2) {
            if (bad[0] + 1 == bad[1]) {
                if (n == 2) cout << x;
                else {
                    cout << min(x, 2 * y);
                }
            }
            else cout << y;
        }
        else cout << (m / 2) * y;
        cout << endl;
        return;
    }
    bad = vector<int>();
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = i ? dp[i - 1] : 0;
        if (a[i] == b[i])continue;
        bad.push_back(i);
        int z = bad.size();
        if (z % 2 == 0) {
            int d = bad[z - 1] - bad[z - 2];
            if (d == 1) dp[i] = dp[bad[z - 2]] + x;
            else {
                dp[i] = dp[bad[z - 2]] + min(x * d, y);
            }
        }
    }
    cout << dp[n - 1] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}