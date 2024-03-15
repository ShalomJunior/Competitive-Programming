#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    deque<pair<int, int>> l, r;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        x < 0 ? l.push_back({ x, a[i] }) : r.push_back({ x, a[i] });
    }
    int hits = 0;
    for (int i = 1; i <= n; i++) {
        hits += k;
        int s = 0;
        while (!l.empty() && l.back().first + i >= 0) {
            s += l.back().second;
            l.pop_back();
        }
        while (!r.empty() && r[0].first - i <= 0) {
            s += r[0].second;
            r.pop_front();
        }
        if (s > hits) {
            cout << "NO" << endl;
            return;
        }
        hits -= s;
    }
    cout << "YES" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
