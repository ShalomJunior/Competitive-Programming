#include <bits/stdc++.h>
using namespace std;

const int N = 30;
const int M = 30;
const int K = 50;
const int INF = 1e9;
int dp[N + 1][M + 1][K + 1];

int go(int r, int c, int k) {
    int& ans = dp[r][c][k];
    if (ans != -1) return ans;
    if (r * c == k || k == 0) return ans = 0;
    ans = INF;
    for (int i = 1; i < r; i++) {
        for (int j = 0; j <= k; j++) {
            ans = min(ans, go(i, c, j) + go(r - i, c, k - j) + c * c);
        }
    }
    for (int j = 1; j < c; j++) {
        for (int i = 0; i <= k; i++) {
            ans = min(ans, go(r, j, i) + go(r, c - j, k - i) + r * r);
        }
    }
    return ans;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    cout << go(n, m, k) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    int t; cin >> t;
    while (t--) solve();
}
