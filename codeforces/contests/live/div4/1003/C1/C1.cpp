#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    a[0] = min(a[0], b[0] - a[0]);
    for (int i = 1; i < n; i++) {
        int x = a[i];
        int y = b[0] - a[i];
        if (x > y) swap(x, y);
        if (x >= a[i - 1]) a[i] = x;
        else a[i] = y;
    }
    cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
