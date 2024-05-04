#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    long long s = accumulate(a.begin(), a.end(), 0LL) + accumulate(b.begin(), b.end(), 0LL);
    vector<vector<bool>> dp(n, vector<bool>(s + 1));
    dp[0][a[0]] = dp[0][b[0]] = true;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= s; j++) {
            if (j - a[i] >= 0) {
                dp[i][j] = dp[i][j] | dp[i - 1][j - a[i]];
            }
            if (j - b[i] >= 0) {
                dp[i][j] = dp[i][j] | dp[i - 1][j - b[i]];
            }
        }
    }
    long long ans = 1e15;
    for (int i = 0; i <= s; i++) {
        if (!dp[n - 1][i]) continue;
        ans = min(ans, i * i + (s - i) * (s - i));
    }
    for (int i = 0; i < n; i++) {
        ans += (n - 2) * a[i] * a[i];
        ans += (n - 2) * b[i] * b[i];
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
