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
    auto cnt = [&](char c) {
        int ans = 0;
        for (int i : {0, n - 1}) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == c) {
                    ans++;
                    break;
                }
            }
        }
        for (int j : {0, m - 1}) {
            for (int i = 0; i < n; i++) {
                if (a[i][j] == c) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
        };
    int x = cnt('B');
    int y = cnt('W');
    cout << (x == 4 || y == 4 ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
