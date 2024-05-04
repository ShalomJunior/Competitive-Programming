#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, r, k; cin >> l >> r >> k;
    int len = r - l + 1;
    int m = len / 2 + (l & 1 && len & 1 ? 1 : 0);
    cout << ((len == 1 && l != 1) || m <= k ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}