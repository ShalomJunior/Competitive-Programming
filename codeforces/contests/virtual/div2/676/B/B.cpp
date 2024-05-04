#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<char>> a, vector<pair<int, int>> b) {
    int n = a.size();
    for (auto& [i, j] : b) {
        a[i][j] = a[i][j] == '0' ? '1' : '0';
    }
    if (a[0][1] == a[1][0] && a[n - 1][n - 2] == a[n - 2][n - 1]) {
        if (a[0][1] != a[n - 1][n - 2]) return true;
    }
    return false;
}

void solve() {
    int n; cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int m = 4;
    vector<pair<int, int>> x = { {0, 1}, {1, 0}, {n - 1, n - 2}, {n - 2, n - 1} };
    for (int i = 0; i < (1 << m); i++) {
        vector<pair<int, int>> id;
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                id.push_back(x[j]);
            }
        }
        if (id.size() > 2) continue;
        if (check(a, id)) {
            cout << id.size() << endl;
            for (auto& [l, r] : id) cout << l + 1 << " " << r + 1 << endl;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}