#include <bits/stdc++.h>
using namespace std;

const int N = 3;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            b[i][j] = c - '0';
        }
    }
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j + 1 < m; j++) {
            int d = b[i][j] - a[i][j];
            d = (d + N) % N;
            if (d == 0) continue;
            a[i][j] += d;
            a[i][j] %= N;
            a[i + 1][j + 1] += d;
            a[i + 1][j + 1] %= N;
            a[i][j + 1] += N - d;
            a[i][j + 1] %= N;
            a[i + 1][j] += N - d;
            a[i + 1][j] %= N;
        }
    }
    cout << (a == b ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
