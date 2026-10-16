#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += abs(a[i] - a[i - 1]);
    }
    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());
    if (mn == mx) {
        cout << max(mx, x) - 1 << endl;
    }
    else if (mn <= 1 && x <= mx) {
        cout << ans << endl;
    }
    else if (1 < mn && mx < x) {
        vector<pair<int, int>> p;
        p.push_back({ abs(a[0] - 1), abs(x - a[0]) });
        p.push_back({ 2 * abs(mn - 1) , 2 * abs(mx - x) });
        p.push_back({ abs(a[n - 1] - 1), abs(a[n - 1] - x) });
        int m = p.size();
        int sup = INF;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i != j || i == 1) {
                    sup = min(sup, p[i].first + p[j].second);
                }
            }
        }
        cout << ans + sup << endl;
    }
    else if (1 < mn) {
        cout << ans + min({ a[0] - 1 , 2 * (mn - 1), abs(a[n - 1] - 1) }) << endl;
    }
    else if (mx < x) {
        cout << ans + min({ abs(x - a[0]) , 2 * abs(mx - x), abs(a[n - 1] - x) }) << endl;
    }
    else {
        assert(false);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
