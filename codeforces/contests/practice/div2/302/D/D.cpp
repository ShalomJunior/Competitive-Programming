#include <bits/stdc++.h>
using namespace std;

const int N = 105;
double dp[N][N][N];

void go(int r, int s, int p, double x) {
    dp[r][s][p] += x;
    if (r + s + p == 0) return;
    int all = r * s + r * p + p * s;
    if (r > 0 && p > 0)
        go(r - 1, s, p, x * r * p / all);
    if (s > 0 && r > 0)
        go(r, s - 1, p, x * r * s / all);
    if (p > 0 && s > 0)
        go(r, s, p - 1, x * p * s / all);
}

void solve() {
    int r, s, p;
    cin >> r >> s >> p;
    go(r, s, p, 1);
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
