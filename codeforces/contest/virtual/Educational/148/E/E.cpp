#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;
void solve() {
    int n, a, x, y, m, k;
    cin >> n >> a >> x >> y >> m >> k;

    int ans = 0;
    vector<int> b(k + 1);
    for (int i = 1; i <= n; i++) {
        vector<int> t(k + 1);
        for (int j = 0; j <= k; j++) {
            t[j] += b[j] + ((j) ? b[j - 1] : a) + ((j == 1) ? a : 0);
            t[j] %= MOD;
        }
        b = t;
        ans ^= (b[k] * i);
        a = (a * x + y) % m;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}