#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    map<int, int> r, c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                r[i]++;
                c[j]++;
            }
        }
    }
    int R = 0;
    for (auto& [k, v] : r) {
        if (r[R] < v) R = k;
    }
    int C = 0;
    for (auto& [k, v] : c) {
        if (c[C] < v) C = k;
    }
    cout << R + 1 << " " << C + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}