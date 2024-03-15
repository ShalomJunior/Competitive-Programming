#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, r, c;
    cin >> n >> m >> r >> c; --r, --c;
    int cnt = 0, tot = 0;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int x = count(a[i].begin(), a[i].end(), 'B');
        tot += x;
        if (i == r && x) cnt = 1;
        if (a[i][c] == 'B') cnt = 1;
    }
    if (tot == 0) cout << -1;
    else if (a[r][c] == 'B') cout << 0;
    else if (cnt) cout << 1;
    else cout << 2;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}