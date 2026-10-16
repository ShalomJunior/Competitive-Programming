#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(k, vector<int>(n));
    vector<vector<int>> p(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            x--;
            a[i][j] = x;
            p[i][x] = j;
        }
    }
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            bool f = true;
            for (int u = 0; u < k; u++) f &= p[u][a[0][j]] < p[u][a[0][i]];
            if (f) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
