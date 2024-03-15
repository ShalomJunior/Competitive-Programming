#include <bits/stdc++.h>
using namespace std;

void solve() {
    int r, c; cin >> r >> c;
    vector<vector<int>> adj(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        string line; cin >> line;
        for (int j = 0; j < c; j++) {
            adj[i][j] = line[j] - '0';
        }
    }
    vector<vector<int>> hash(r, vector<int>(c));
    vector<vector<bool>> vis(r, vector<bool>(c));
    function<void(int, int, int)> dfs = [&](int ri, int ci, int h) {
        vis[ri][ci] = true;
        hash[ri][ci] = h;
        for (int i : {-1, 1}) {
            int x = ri + i;
            if (0 <= x && x < r && adj[x][ci] == adj[ri][ci] && !vis[x][ci]) {
                dfs(x, ci, h);
            }
        }
        for (int j : {-1, 1}) {
            int y = ci + j;
            if (0 <= y && y < c && adj[ri][y] == adj[ri][ci] && !vis[ri][y]) {
                dfs(ri, y, h);
            }
        }
        };
    for (int h = 1, i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!vis[i][j]) dfs(i, j, h++);
        }
    }
    int n; cin >> n;
    while (n--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        --r1;--c1; --r2; --c2;
        if (adj[r1][c1] != adj[r2][c2]) cout << "neither";
        else {
            if (hash[r1][c1] != hash[r2][c2]) cout << "neither";
            else cout << (adj[r1][c1] ? "decimal" : "binary");
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
