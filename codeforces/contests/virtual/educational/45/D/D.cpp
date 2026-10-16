#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a == 1 && b == 1 && (n == 2 || n == 3)) {
        cout << "NO" << endl;
        return;
    }
    if (a == 1) {
        cout << "YES" << endl;
        set<pair<int, int>> s;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                s.insert({ i, j });
            }
        }
        for (int i = 0; i < b; i++) {
            for (int j = i + b; j < n; j += b) {
                s.erase({ j - b, j });
            }
        }
        vector<vector<int>> g(n, vector<int>(n));
        for (auto& [u, v] : s) {
            g[u][v] = g[v][u] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << g[i][j];
            }
            cout << endl;
        }
    }
    else if (b == 1) {
        cout << "YES" << endl;
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < a; i++) {
            for (int j = i + a; j < n; j += a) {
                g[j - b][j] = g[j][j - b] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << g[i][j];
            }
            cout << endl;
        }
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
