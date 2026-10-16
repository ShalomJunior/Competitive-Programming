#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto& [p, v] : a) cin >> p >> v;
    sort(a.begin(), a.end());
    int ans = 0;
    int j = n - 1;
    while (j >= 0 && a[j].first + 1 >= a[n - 1].first) {
        ans = max(ans, a[j].second);
        j--;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}