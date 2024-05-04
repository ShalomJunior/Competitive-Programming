#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
vector<int> fact(N);
int exp(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int inv(int a, int mod) {
    return exp(a, MOD - 2, MOD);
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> f(m);
    for (auto& c : f) cin >> c;
    int tot = accumulate(f.begin(), f.end(), 0LL);
    tot %= MOD;
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        int cnt = exp(m, i - 1, MOD);
        int add = (cnt * tot) % MOD;
        add = (add * fact[m] % MOD);
        ans += add;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = (fact[i - 1] * i) % MOD;
    int t; cin >> t;
    while (t--)solve();
}
