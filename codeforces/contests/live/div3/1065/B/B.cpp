#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    if (a[0] == -1) {
        if (a[n - 1] == -1) {
            a[0] = a[n - 1] = 0;
        }
        else {
            a[0] = a[n - 1];
        }
    }
    else {
        if (a[n - 1] == -1) {
            a[n - 1] = a[0];
        }
    }
    int ans = 0;
    for (int i = 0; i + 1 < n; i++) ans += a[i + 1] - a[i];
    cout << abs(ans) << endl;
    for (auto& c : a) cout << max(c, 0LL) << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
