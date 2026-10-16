#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
        a[i][m] = i + 1;
    }
    for (auto& v : a) {
        sort(v.begin(), v.end() - 1);
    }
    sort(a.begin(), a.end());
    int v = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (a[i][j] != v) {
                cout << -1 << endl;
                return;
            }
            v++;
        }
    }
    for (int i = 0; i < n; i++) cout << a[i][m] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
