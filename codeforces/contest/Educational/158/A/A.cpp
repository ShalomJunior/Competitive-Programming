#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a = { 0 };
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, a[i + 1] - a[i]);
    }
    ans = max(ans, 2 * (x - a.back()));
    cout << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
