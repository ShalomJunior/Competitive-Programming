#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
void solve() {
    int n; cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        cnt[c]++;
    }
    int z = 0;
    while (cnt.count(z)) z++;
    if (!z) {
        cout << 0 << endl;
        return;
    }
    int dp[z][z + 1];
    int mn[z + 1];
    for (int i = 0; i < z; i++) {
        for (int j = 0; j <= z; j++) {
            dp[i][j] = INF;
            mn[j] = INF;
        }
    }
    for (int i = 0; i < z; i++) {
        for (int mex = i + 1; mex <= z; mex++) {
            dp[i][mex] = mex * (cnt[i] - 1) + i + (i ? mn[i] : 0);
            mn[mex] = min(mn[mex], dp[i][mex]);
        }
    }
    int ans = INF;
    for (int i = 0; i < z; i++) ans = min(ans, dp[i][z]);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}