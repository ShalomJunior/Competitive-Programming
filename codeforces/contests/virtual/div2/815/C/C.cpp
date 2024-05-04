#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    char grid[n][m];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            cnt += grid[i][j] == '1';
        }
    }
    if (cnt == n * m) {
        cout << n * m - 2 << endl;
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            int in = 0;
            for (int x : {i, i + 1}) {
                for (int y : {j, j + 1}) {
                    in += grid[x][y] == '0';
                }
            }
            if (in >= 2) {
                cout << cnt << endl;
                return;
            }
        }
    }
    cout << (cnt ? cnt - 1 : 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}