#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (auto& [l, r] : p) cin >> l >> r;
    int ans = 0;
    map<pair<int, int>, map<int, int>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int x = p[i].first - p[j].first;
            int y = p[i].second - p[j].second;
            mp[{x, y}][i]++;
            mp[{x, y}][j]++;
            mp[{x, y}][n]++;
        }
    }
    for (auto& [p, h] : mp) {

    }
    cout << ans / 4 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
