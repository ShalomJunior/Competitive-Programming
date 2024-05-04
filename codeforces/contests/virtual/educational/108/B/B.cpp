#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int x = (n - 1) + (m - 1) * n;
    int y = (m - 1) + (n - 1) * m;
    if (x > y) swap(x, y);
    cout << (x <= k && k <= y ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
