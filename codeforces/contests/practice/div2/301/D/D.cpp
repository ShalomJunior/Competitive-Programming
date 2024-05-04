#include <bits/stdc++.h>
using namespace std;

const int N = 105;
double dp[N][N][N];
bool vis[N][N][N];
int r, s, p;

double w(int x, int y, int z) {
    int num = x * y;
    int den = x * y + x * z + y * z;
    //assert(den != 0);
    return (den ? (double)num / den : 0);
}

double go(int a, int b, int c) {
    cerr << a << " " << b << " " << c << endl;
    if (a > r || b > s || c > p || a + b + c == 0) {
        cerr << "res " << 0 << endl << endl;
        return 0;
    }
    if (vis[a][b][c]) return dp[r][s][p];
    vis[a][b][c] = true;
    if (a == r && b == s && c == p) {
        cerr << "res " << 1 << endl << endl;
        dp[a][b][c] = 1;
    }
    else {
        dp[a][b][c] += go(a, b + 1, c) * w(a, b + 1, c);
        cerr << "-> " << dp[a][b][c] << endl;
        dp[a][b][c] += go(a + 1, b, c) * w(a + 1, c, b);
        cerr << "| " << dp[a][b][c] << endl;
        dp[a][b][c] += go(a, b, c + 1) * w(b, c + 1, a);
        cerr << "< " << dp[a][b][c] << endl;
    }
    cerr << "res " << dp[a][b][c] << endl << endl;
    return dp[a][b][c];
}

void solve() {
    cin >> r >> s >> p;
    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= s; j++) {
            for (int k = 0; k <= p; k++) {
                if (vis[i][j][k] == false) {
                    go(i, j, k);
                }
                cerr << i << " " << j << " " << k << " " << dp[i][j][k] << endl;

            }
        }
    }
    double x = 0;
    for (int i = 1; i <= r; i++) {
        x += dp[i][0][0];
    }
    double y = 0;
    for (int j = 1; j <= s; j++) {
        y += dp[0][j][0];
    }
    double z = 0;
    for (int k = 1; k <= p; k++) {
        z += dp[0][0][k];
    }
    cout << fixed << setprecision(12);
    cout << x << " " << y << " " << z << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
