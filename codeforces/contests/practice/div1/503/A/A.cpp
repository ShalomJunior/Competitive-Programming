#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<multiset<int>> a(m + 1);
    for (int i = 1; i <= n; i++) {
        int p, c;
        cin >> p >> c;
        a[p].insert(c);
    }
    if (m == 1) {
        cout << 0 << endl;
        return;
    }
    int mx = 0;
    for (int i = 2; i <= m; i++) mx = max(mx, (int)a[i].size());
    int ans = INF;
    for (int i = mx; i >= 0; i--) {
        int cnt = a[1].size();
        int cost = 0;
        auto b = a;
        multiset<int> r;
        for (int j = 2; j <= m; j++) {
            while (b[j].size() > i) {
                cost += *b[j].begin();
                b[j].erase(b[j].begin());
                cnt++;
            }
            while (!b[j].empty()) {
                r.insert(*b[j].begin());
                b[j].erase(b[j].begin());
            }
        }
        while (cnt <= i && !r.empty()) {
            cost += *r.begin();
            r.erase(r.begin());
            cnt++;
        }
        if (cnt > i) ans = min(ans, cost);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}