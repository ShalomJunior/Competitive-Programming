#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    char g[n][m];
    vector<int> r, c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'B') {
                r.push_back(i);
                c.push_back(j);
            }
        }
    }
    if (r.empty()) {
        cout << "1 1" << endl;
        return;
    }
    sort(r.begin(), r.end());
    sort(c.begin(), c.end());
    int rx = (r[0] + r.back()) / 2;
    int cy = (c[0] + c.back()) / 2;
    int R = 0, C = 0;
    int D = 1e9;
    for (int x = rx - 10; x <= rx + 10; x++) {
        for (int y = cy - 10; y <= cy + 10; y++) {
            if (x < 0 || y < 0 || x >= n || y >= m) continue;
            int d = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (g[i][j] == 'B') {
                        d = max(d, abs(i - x) + abs(j - y));
                    }
                }
            }
            if (d < D) {
                R = x, C = y;
                D = d;
            }
        }
    }
    cout << R + 1 << " " << C + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}