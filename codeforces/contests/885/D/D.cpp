#include <bits/stdc++.h>
using namespace std;

const int N = 105;
bool grid[N][N];
int n, m, k;

bool f(int x, int y) {
    if (x < 1 || x > n) return false;
    if (y < 1 || y > m) return false;
    return true;
}

bool go(int x, int y) {
    for (int i : {-1, 1}) {
        int dx = x + i, dy = y + i;
        if (f(dx, y) && grid[dx][y]) return false;
        if (f(x, dy) && grid[x][dy]) return false;
    }
    return true;
}

void solve() {
    cin >> n >> m >> k;
    int a, b; cin >> a >> b;
    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        grid[x][y] = true;
    }
    for (int i : {-1, 1}) {
        int da = a + i, db = b + i;
        if (f(da, b) && go(da, b) || f(a, db) && go(a, db)) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}