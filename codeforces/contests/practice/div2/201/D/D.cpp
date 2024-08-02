#include<bits/stdc++.h>
using namespace std;

const int N = 105;
const int INF = 1e9;
int dp[N][N][N];
void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    int x = a.length();
    int y = b.length();
    int z = c.length();
    a = "#" + a;
    b = "#" + b;
    c = "#" + c;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            for (int k = 0; k < z; k++) {
                if (min(i, j) < k) {
                    dp[i][j][k] = -INF;
                    continue;
                }
                if (i == 0 || j == 0) {
                    dp[i][j][k] = 0;
                    continue;
                }
                if (a[i] == b[j]) {
                    if (k == 0) {

                    }
                    else {
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] == -INF ?

                    }
                }
                else {

                }
            }
        }
    }
    int ans = 0;
    for (int k = 0; k < z; k++) ans = max(ans, dp[x][y][k]);
    cout << ans << endl;
}

// if (X[i - 1] == Y[j - 1]) {
//     table[i][j] = table[i - 1][j - 1] + 1;
// }
// else {
//     table[i][j] = max(table[i - 1][j], table[i][j - 1]);
// }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

