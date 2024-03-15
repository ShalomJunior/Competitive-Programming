#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
int modpow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return res;
}

void solve() {
    int k; cin >> k;
    int ans = modpow(4, (1LL << k) - 2);
    ans = (ans * 6) % MOD;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}