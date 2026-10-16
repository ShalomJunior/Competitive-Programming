#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, m;
    cin >> n >> x >> m;
    int L = x, R = x;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        if (r < L || R < l) continue;
        L = min(L, l);
        R = max(R, r);
    }
    cout << R - L + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
