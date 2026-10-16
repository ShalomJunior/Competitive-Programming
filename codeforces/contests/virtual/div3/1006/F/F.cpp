#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i].resize(i + 1);
        a[i][1] = k;
        a[i][i] = k;
        for (int j = 2; j < i; j++) {
            a[i][j] = a[i - 1][j] ^ a[i][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << a[i][j] << " ";
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