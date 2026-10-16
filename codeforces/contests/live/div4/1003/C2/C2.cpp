#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    set<int> s(b.begin(), b.end());
    a[0] = min(a[0], *s.begin() - a[0]);
    for (int i = 1; i < n; i++) {
        int x = a[i];
        auto it = s.lower_bound(a[i] + a[i - 1]);
        if (it != s.end()) {
            int y = *it - a[i];
            if (x > y) swap(x, y);
            if (a[i - 1] <= x) a[i] = x;
            else a[i] = y;
        }
    }
    cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
