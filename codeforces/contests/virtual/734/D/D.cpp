#include <bits/stdc++.h>
#define Mine vector<vector<int>> 
using namespace std;

int r, c;
bool good(int i, int j) { return (i >= 0 && i < r && j >= 0 && j < c); }

int cnt(Mine& v, int x, int y) {
    int ans = 0;
    for (int a : {-1, 1}) {
        for (int b : {-1, 1}) {
            int i = 0;
            while (good(x + i * a, y + i * b)) { ans += v[x + i * a][y + i * b]; i++; }
        }
    }
    ans -= 3 * v[x][y];
    return ans;
}

void solve() {
    cin >> r >> c; Mine v(r);
    for (int i = 0; i < r; i++) {
        v[i].resize(c);
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ans = max(ans, cnt(v, i, j));
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}