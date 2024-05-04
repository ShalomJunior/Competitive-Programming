#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> cost(N, N);

void init() {
    cost[1] = 0;
    for (int i = 1; i < N; ++i) {
        for (int x = 1; x <= i; ++x) {
            int j = i + i / x;
            if (j < N) cost[j] = min(cost[j], cost[i] + 1);
        }
    }
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> b(n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        tot += cost[b[i]];
    }
    vector<int> c(n);
    for (auto& x : c) cin >> x;
    if (k >= tot) {
        cout << accumulate(c.begin(), c.end(), 0LL) << endl;
        return;
    }
    vector<vector<long long>> dp(n, vector<long long>(k + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j >= cost[b[i]]) {
                dp[i][j] = c[i];
                if (i - 1 >= 0) dp[i][j] += dp[i - 1][j - cost[b[i]]];
            }
            if (i - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    cout << dp[n - 1][k] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin >> t;
    while (t--) solve();
}