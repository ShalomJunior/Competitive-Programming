#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), d(n);
    for (auto& c : a) cin >> c;
    for (auto& c : d) cin >> c;
    set<int> alive;
    for (int i = 0; i < n; i++)alive.insert(i);
    set<pair<int, int>> end;
    for (int i = 0; i < n; i++) {
        int delta = 0;
        if (i - 1 >= 0) delta += a[i - 1];
        if (i + 1 < n) delta += a[i + 1];
        int t = a
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
