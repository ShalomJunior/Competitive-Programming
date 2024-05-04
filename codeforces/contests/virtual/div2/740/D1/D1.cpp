#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> dp(n + 1);
    vector<int> pre(n + 1);
    dp[1] = pre[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = pre[i - 1];
        int j;
        for (j = 1; j * j <= i; j++) {
            int l = i / (j + 1) + 1;
            int r = i / j;
            int cnt = r - l + 1;
            int add = (1LL * cnt * dp[j]) % m;
            dp[i] = (dp[i] + add) % m;
            if (j >= 2 && l > sqrt(i) && j * j != i) dp[i] = (dp[i] + dp[r]) % m;
        }
        pre[i] = (pre[i - 1] + dp[i]) % m;
    }
    cout << dp[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

