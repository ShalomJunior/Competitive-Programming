#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
int power(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}
void solve() {
    int x, y;
    cin >> x >> y;
    if (y % x) {
        cout << 0 << endl;
        return;
    }
    map<int, int> mp;
    mp[1] = 1;
    function<int(int)> go = [&](int k) {
        if (mp.find(k) != mp.end()) return mp[k];
        int ans = power(2, k - 1, MOD) - 1;
        for (int i = 2; i * i <= k; i++) {
            if (k % i) continue;
            int d1 = i;
            int d2 = k / i;
            ans -= go(d1);
            if (d1 != d2) ans -= go(d2);
        }
        return mp[k] = ans % MOD;
        };
    int ans = go(y / x);
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}