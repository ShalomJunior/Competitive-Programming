#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
void solve() {
    int n, x;
    cin >> n >> x;
    set<int> all;
    vector<int> a(n);
    for (auto& c : a) {
        cin >> c;
        for (int i = 1; i * i <= c; i++) {
            if (c % i == 0) {
                if (i % x == 0) {
                    all.insert(i);
                }
                if (i * i < c && (c / i) % x == 0) {
                    all.insert(c / i);
                }
            }
        }
    }
    all.insert(x);
    vector<map<int, int>> dp(n);
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            dp[i] = dp[i - 1];
            for (auto& c : all) {
                int ng = __gcd(c, a[i]);
                if (ng % x == 0) {
                    if (ng == c) {
                        dp[i][ng] += dp[i - 1][c];
                    }
                    else {
                        dp[i][ng] += dp[i - 1][c];
                    }
                }
                dp[i][ng] %= MOD;
            }
        }
        if (a[i] % x == 0) {
            dp[i][a[i]]++;
            dp[i][a[i]] %= MOD;
        }
    }
    cout << dp[n - 1][x] % MOD << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}