#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> grid(2, vector<char>(n));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> f(2, vector<bool>(n));
    vector<vector<bool>> g(2, vector<bool>(n));
    function<void(int, int, int)> go = [&](int i, int j, int s) {
        if (s == 0) {
            if (f[i][j])return;
            f[i][j] = true;
            for (int di : { -1, 1 }) {
                int ni = i + di;
                if (0 <= ni && ni < 2)go(ni, j, 1);
            }
            for (int dj : {-1, 1}) {
                int nj = j + dj;
                if (0 <= nj && nj < n)go(i, nj, 1);
            }
        }
        else {
            if (g[i][j])return;
            g[i][j] = true;
            grid[i][j] == '>' ? go(i, j + 1, 0) : go(i, j - 1, 0);
        }
        };
    go(0, 0, 0);
    cout << (f[1][n - 1] | g[1][n - 1] ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
