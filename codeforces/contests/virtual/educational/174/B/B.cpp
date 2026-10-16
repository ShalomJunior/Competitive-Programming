#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    int n, m;
    cin >> n >> m;
    vector<int> h(n * m);
    vector<vector<int>> a(n, vector<int>(m));
    set<int> cols;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j]--;
            h[a[i][j]] = max(h[a[i][j]], 1);
            cols.insert(a[i][j]);
            if (i) {
                h[a[i][j]] = max(h[a[i][j]], a[i - 1][j] == a[i][j] ? 2 : 1);
            }
            if (j) {
                h[a[i][j]] = max(h[a[i][j]], a[i][j - 1] == a[i][j] ? 2 : 1);
            }
        }
    }
    if (cols.size() > 1) {
        int mx = 0;
        int tot = 0;
        for (auto& c : h) {
            mx = max(mx, c);
            tot += c;
        }
        cout << tot - mx;
    }
    else {
        cout << 0;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve(t);
}