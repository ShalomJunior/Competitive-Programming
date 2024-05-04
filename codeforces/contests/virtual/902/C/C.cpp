#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    if (k > 3) {
        cout << 0 << endl;
        return;
    }
    int r = n - k + 2;
    int ans = 1 + (m < r ? 0 : (m - r) / n);
    cout << max(ans, 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}