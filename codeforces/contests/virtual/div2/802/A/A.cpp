#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << 1;
    }
    else {
        int x = (m * (m + 1) / 2) + m * (n * (n + 1) / 2);
        x -= m;
        int y = n + m * (n * (n - 1) / 2) + m * ((n * m - m + 1) + n * m) / 2;
        y -= (1 + m * (n - 1));
        cout << min(x, y);
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}