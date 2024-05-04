#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if (n == 2) {
        cout << -1 << endl;
        return;
    }
    int ans[n][n];
    int v = 1;
    for (int c = 0; c < n; c++) {
        for (int r = 0; r < n; r++) {
            ans[r][c] = v;
            v = (v + 2 <= n * n ? v + 2 : 2);
        }
    }
    for (auto& vec : ans) {
        for (auto& c : vec) cout << c << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
