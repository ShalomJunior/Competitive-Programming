#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        int s = 0;
        for (int j = i, t = m; j && t; j--, t--) {
            s += a[j];
            dp[i] = max(dp[i], dp[j - 1] + s - k);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}