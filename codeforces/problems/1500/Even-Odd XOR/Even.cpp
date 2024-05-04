#include <bits/stdc++.h>
using namespace std;

const int M = INT_MAX;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = M - 2 * i + (i & 1);
    }
    if (n & 1) {
        v[n - 1] = ((n / 2) & 1) ? 1 : 0;
    }
    else {
        v[n - 1] = ((n / 2) & 1) ? 1 : v[n - 1];
    }

    int o = 0, e = 0;
    for (int i = 0; i < n; i++) {
        (i & 1) ? o ^= v[i] : e ^= v[i];
    }
    cout << ((o == e) ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}