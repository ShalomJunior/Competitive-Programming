#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector<pair<int, int>> X(n);
    for (auto& p : X) cin >> p.first;
    for (auto& p : X) cin >> p.second;
    sort(X.begin(), X.end());
    map<int, vector<int>> mp;
    for (auto& [l, r] : X) {
        mp[l].push_back(r);
    }
    int last = x1;
    int h1 = y1;
    int h2 = y1;
    map<int, pair<int, int>> dp;
    for (auto& [k, v] : mp) {
        int f = v[0];
        int s = v.back();
        int tm = k - last;
        int t1 = (h1 > f ? h1 - f : 0) + s - f;
        int t2 = (h1 < s ? s - h1 : 0) + s - f;
        dp[k].first = t1;
        dp[k].second = t2;
        t1 = (h2 > f ? h2 - f : 0) + s - f;
        t2 = (h2 < s ? s - h2 : 0) + s - f;
        dp[k].first = min(dp[k].first, t1);
        dp[k].second = min(dp[k].second, t2);
        last = k;
    }

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}