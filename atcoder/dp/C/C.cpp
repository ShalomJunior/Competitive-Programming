#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> dp(3);
    for (int i = 0; i < n; i++) {
        vector<int>c(3);
        vector<int> tdp(3, 0);
        for (auto& t : c) cin >> t;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    tdp[i] = max(dp[i], dp[i] + c[j]);
                }
            }
        }
        dp = tdp;
    }

    cout << max({ dp[0], dp[1], dp[2] }) << endl;
}