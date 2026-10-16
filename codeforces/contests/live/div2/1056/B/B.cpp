#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int w = n * n;
    if (k == w - 1) {
        cout << "NO" << endl;
        return;
    }
    vector<vector<char>> g(n, vector<char>(n, 'L'));
    int r = k / n;
    int c = k % n;
    for (int i = 0, cnt = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cnt < k) {
                g[i][j] = 'U';
                cnt++;
            }
        }
    }
    if (c > 0) {
        int rem = n - c;
        if (rem == 1) {
            g[r][c] = 'D';
        }
        else {
            g[r][c] = 'R';
        }
    }
    if (c == 0) r--;
    for (int i = r + 1; i < n; i++) {
        g[i][0] = 'R';
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << g[i][j];
        }
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
