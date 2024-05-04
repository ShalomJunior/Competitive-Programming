#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    vector<int> b;
    for (int i = 1; i < n; i++) {
        int d = a[i] - a[i - 1];
        if (d > x) {
            b.push_back(d / x + (d % x ? 0 : -1));
        }
    }
    sort(b.begin(), b.end());
    int ans = b.size() + 1;
    for (int i = 0, s = 0; i < b.size() && s + b[i] <= k; i++) {
        s += b[i];
        ans--;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}