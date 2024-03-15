#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;


int main() {
    int n, x; cin >> n >> x;
    vector<int> coins(n), dp(x + 1, INF);

    coins.resize(n);
    for (auto& u : coins) cin >> u;

    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (auto& c : coins) {
            if (i - c >= 0 && dp[i - c] != INF) {
                dp[i] = min(dp[i], 1 + dp[i - c]);
            }
        }
    }

    if (dp[x] == INF) {
        cout << "-1" << endl;
    }
    else {
        cout << dp[x] << endl;
    }
}