#include <bits/stdc++.h>
#define int long long
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

void solve() {
    int n; cin >> n;
    vector<Mine> vec(n);
    for (auto& p : vec)cin >> p.F;
    for (auto& p : vec)cin >> p.S;
    sort(vec.begin(), vec.end());
    int ans = 0;
    for (int m = 1; m * m <= 2 * n; m++) {
        vector<int> cnt(n + 1);
        for (auto& [a, b] : vec) {
            int bj = a * m - b;
            if (1 <= bj && bj <= n) ans += cnt[bj];
            if (a == m)cnt[b]++;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}