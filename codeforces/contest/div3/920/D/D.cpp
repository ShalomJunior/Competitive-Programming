#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    multiset<int> ma(a.begin(), a.end());
    multiset<int> mb(b.begin(), b.end());
    int ans = 0;
    while (!ma.empty()) {
        int x = *ma.begin(), y = *prev(ma.end());
        int u = *mb.begin(), v = *prev(mb.end());
        vector<pair<int, int>> p;
        p.push_back({ x, u });
        p.push_back({ x, v });
        p.push_back({ y, u });
        p.push_back({ y, v });
        sort(p.begin(), p.end(), [&](const pair<int, int>& p1, const pair<int, int>& p2) {
            return abs(p1.first - p1.second) > abs(p2.first - p2.second);
            });
        ans += abs(p[0].first - p[0].second);
        ma.erase(ma.find(p[0].first));
        mb.erase(mb.find(p[0].second));
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}