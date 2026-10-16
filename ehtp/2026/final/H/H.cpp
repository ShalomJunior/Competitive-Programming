#include<bits/stdc++.h>
#define int long long
using namespace std;

const int K = 2005;
const int MOD = 1e9 + 7;
vector<vector<int>> D(K);

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    dp[n] = vector<int>(k + 1, 1);
    for (int i = n - 1; i > 0; i--) {
        for (int j = 1; j <= k; j++) {
            for (auto& x : D[j]) {
                dp[i][x] += dp[i + 1][j];
                dp[i][x] %= MOD;
            }
        }
    }
    int ans = accumulate(dp[1].begin() + 1, dp[1].end(), 0LL) % MOD;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i < K; i++) {
        for (int j = i; j < K; j += i) {
            D[j].push_back(i);
        }
    }
    solve();
}