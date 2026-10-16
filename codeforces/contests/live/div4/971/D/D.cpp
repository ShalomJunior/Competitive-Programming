    #include <bits/stdc++.h>
    #define int long long 
    using namespace std;

    void solve() {
        int n;
        cin >> n;
        map<int, set<int>> h;
        int cnt_x = 0;
        int cnt_y = 0;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            h[x].insert(y);
            cnt_x += y == 0;
            cnt_y += y == 1;
        }
        int ans = 0;    
        for (auto& [k, v] : h) {
            int m = v.size();
            if (m == 2) {
                ans += cnt_x - 1;
                ans += cnt_y - 1;
            }
            for (auto& y : v) {
                if (y == 0) {
                    if (h[k - 1].count(1) && h[k + 1].count(1)) ans++;
                }
                else {
                    if (h[k - 1].count(0) && h[k + 1].count(0)) ans++;
                }
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
