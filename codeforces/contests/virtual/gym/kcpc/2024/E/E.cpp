#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e7;
const int MOD = 1e9 + 7;
vector<int> f(N);
vector<int> inv(N);

int order(int n, int k) {
    if (k > n) return 0;
    return f[n] * inv[n - k] % MOD;
}

int pow(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int can = n - k + 1;
    int r = n - k;
    cerr << "or " << order(k, 2) << endl;
    int m = can * (k - 1)
        int ans = (k - 1)
        * f[n - 2] % MOD;
    cerr << "ans" << ans << endl;
    ans = ans * can % MOD;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    f[0] = 1;
    for (int i = 1; i < N; i++) f[i] = f[i - 1] * i % MOD;
    inv[N - 1] = pow(f[N - 1], MOD - 2, MOD);
    for (int i = N - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
    int t; cin >> t;
    while (t--) solve();
}