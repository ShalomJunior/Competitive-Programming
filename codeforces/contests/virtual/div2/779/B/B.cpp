#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2000;
const int MOD = 998244353;
int f[N];
void init() {
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = (f[i - 1] * i) % MOD;
    }
}
void solve() {
    int n;
    cin >> n;
    if (n & 1) {
        cout << 0 << endl;
        return;
    }
    cout << f[n / 2] * f[n / 2] % MOD << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin >> t;
    while (t--)solve();
}