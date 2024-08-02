#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int cnt = count(a.begin(), a.end(), a[0]);
    if (cnt == n) {
        cout << -1 << endl;
        return;
    }
    if (a[0] != a[n - 1]) {
        cout << 0 << endl;
        return;
    }
    int ans = 1e9;
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != a[0]) {
            ans = min(ans, m);
            m = 0;
        }
        else m++;
    }
    ans = min(ans, m);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
