#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    if (k >= 3) {
        cout << 0 << endl;
        return;
    }
    sort(a.begin(), a.end());
    int x = a[0], y = a[0];
    for (int i = 0; i < n; i++) {
        if (i < n - 1) x = min(x, a[i + 1] - a[i]);
        for (int j = i + 1; j < n; j++) {
            int diff = a[j] - a[i];
            auto it = lower_bound(a.begin(), a.end(), diff);
            if (it != a.end()) y = min(y, *it - diff);
            if (it != a.begin()) y = min(y, diff - *(it - 1));
        }
    }
    cout << (k == 1 ? x : min(x, y)) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
