#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x % m]++;
    }
    int ans = (a[0] ? 1 : 0);
    for (int i = 1, j = m - 1; i <= j; i++, j--) {
        if (a[i] + a[j]) {
            ans++;
            int r = abs(a[i] - a[j]);
            if (i != j) ans += max(r - 1, 0);
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}