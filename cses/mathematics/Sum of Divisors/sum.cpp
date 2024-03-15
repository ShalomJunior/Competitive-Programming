#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
void solve() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans = (ans + i) % MOD;
            if (n / i != i) {
                ans = (ans + n / i) % MOD;
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}