#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n), v(k);
    for (auto& c : a) cin >> c;
    for (auto& c : v) cin >> c;
    int ans = 0;
    for (int i = 0; i < min(2 * n, d); i++) {
        int eq = 0;
        for (int j = 0; j < n; j++) {
            eq += (a[j] == j + 1);
            a[j] += (j + 1 <= v[i % k]);
        }
        ans = max(ans, eq + (d - i - 1) / 2);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
