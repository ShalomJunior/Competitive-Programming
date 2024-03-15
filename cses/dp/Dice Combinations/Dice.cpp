#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n; cin >> n;

    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n;i++) {
        for (int c = 1; c <= 6; c++) {
            if (i - c >= 0) {
                dp[i] += dp[i - c];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[n] << endl;
}