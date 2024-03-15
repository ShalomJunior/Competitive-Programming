#include <bits/stdc++.h>
using namespace std;

void solve() {
    int r, c; cin >> r >> c;
    vector<vector<char>> g(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> g[i][j];
        }
    }
    int cnt = 0;
    vector<vector<bool>> vis(r, vector<bool>(c));
    function<void(int, int)> dfs = [&](int dr, int dc) {
        vis[dr][dc] = true;
        cnt++;
        for (int d : {1}) {
            if (0 <= dr + d && dr + d < r && g[dr + d][dc] != '#' && !vis[dr + d][dc])
                dfs(dr + d, dc);
        }
        for (int d : {-1, 1}) {
            if (0 <= dc + d && dc + d < c && g[dr][dc + d] != '#' && !vis[dr][dc + d])
                dfs(dr, dc + d);
        }
        };
    for (int j = 0; j < c; j++) {
        if (g[0][j] == '.' && !vis[0][j])
            dfs(0, j);
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
