#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 25, M = 25;

int n, m, k;
int a[N][M];
map<int, int> dp[N][M];
set<pair<int, int>> Endpoints;

void f(int i, int j, int lim, int x) {
    x ^= a[i][j];
    if (lim == 0) {
        dp[i][j][x]++;
        Endpoints.insert({ i, j });
        return;
    }
    if (i + 1 < n) f(i + 1, j, lim - 1, x);
    if (j + 1 < m) f(i, j + 1, lim - 1, x);
}

void g(int i, int j, int lim, int x) {
    x ^= a[i][j];
    if (lim == 0) {
        dp[i][j][x]++;
        return;
    }
    if (i - 1 >= 0) g(i - 1, j, lim - 1, x);
    if (j - 1 >= 0) g(i, j - 1, lim - 1, x);
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int move = n + m - 2;
    int mid = move / 2;
    f(0, 0, mid, 0);
    g(n - 1, m - 1, move - mid - 1, 0);
    int ans = 0;
    for (auto it = Endpoints.begin(); it != Endpoints.end(); it++) {
        int i = it->first, j = it->second;
        for (auto& [x, cnt] : dp[i][j]) {
            if (i == n - 1 && j == m - 1) {
                if (x == k) ans += cnt;
                continue;
            }
            int y = k ^ x;
            if (i + 1 < n) {
                ans += cnt * dp[i + 1][j][y];
            }
            if (j + 1 < m) {
                ans += cnt * dp[i][j + 1][y];
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}