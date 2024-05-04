#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        int r, t; cin >> r >> t;
        ans = min(ans, r + (t - 1) / 2);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
