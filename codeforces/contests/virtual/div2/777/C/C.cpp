#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<char>> g(n, vector<char>(m, '0'));
    int q = 0;
    stringstream ss;
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '1') {
                ss << i << " " << j + 1 << " " << i + 1 << " " << j + 1 << endl;
                g[i][j] = '1';
                q++;
            }
        }
    }
    for (int j = m - 1; j > 0; j--) {
        if (a[0][j] == '1') {
            ss << 1 << " " << j << " " << 1 << " " << j + 1 << endl;
            g[0][j] = '1';
            q++;
        }
    }
    if (g != a) {
        cout << -1 << endl;
    }
    else {
        cout << q << endl;
        cout << ss.str();
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}