#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;
const int INF = 2 * 1e9;

int main() {
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for (auto& c : coins) cin >> c;

    sort(coins.begin(), coins.end());
    int dp[x + 1][2];
    dp[0][0] = 1;
    for (int i = 1; i <= x; i++) {
        for (auto& c : coins) {
            if (i - c >= 0) {
                dp[i] += dp[i - c];
                dp[i] %= M;
            }
        }
    }
    cout << dp[x] << endl;
}