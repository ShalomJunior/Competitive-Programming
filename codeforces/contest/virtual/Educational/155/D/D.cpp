#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;
const int N = 30;
int dp[N][2][2];

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    for (int i = 0; i < N; i++) {
        dp[i][0][0] = 1;
        dp[i][0][1] = -1;
    }
    int ans = 0, x = 0;
    for (int i = 0; i < n; i++) {
        x ^= a[i];
        for (int j = 0; j < N; j++) {
            int mask = 1 << j;
            int b = (x >> j) & 1;
            int len = (dp[j][b ^ 1][0] * i - dp[j][b ^ 1][1]) % MOD;
            ans += (len * (1 << j)) % MOD;
            ans %= MOD;
            dp[j][b][0]++;
            dp[j][b][1] += i;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}