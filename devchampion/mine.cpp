#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e4;

int dp[N + 1][N + 1];

void add(int& x, int y) { x = (x + y) % MOD; }

void prepare() {
    dp[0][1] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (j <= i) {
                add(dp[i][j], dp[i - 1][j - 1]);
                add(dp[i][j], dp[i - j][j]);
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    if (n & 1) {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        add(ans, dp[n / 2][i]);
    }
    cout << (ans ? ans - 1 : MOD - 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--) solve();
}