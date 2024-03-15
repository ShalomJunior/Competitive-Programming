#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), v(n + 1, 1e7);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v[a[i]] = min(v[a[i]], i);
    }
    vector<int> dp(n), best(n + 1);
    best[a[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (v[a[i]] == i) {
            best[a[i]] = i;
            dp[i] = dp[i - 1];
        }
        else {
            int k = best[a[i]];
            int curr = i - k + 1 + (k - 1 < 0 ? 0 : dp[k - 1]);
            dp[i] = max(dp[i - 1], curr);
            if (dp[i - 1] > i - k + (k - 1 < 0 ? 0 : dp[k - 1])) best[a[i]] = i;
        }
    }
    cout << dp[n - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}