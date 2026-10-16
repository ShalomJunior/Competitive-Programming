#include <bits/stdc++.h>
#define int long long
using namespace std;

auto divs(int n) {
    vector<int> d;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (i * i < n) d.push_back(n / i);
        }
    }
    return d;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    map<int, vector<int>> h;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        h[a[i]].push_back(i);
    }
    while (q--) {
        int k, l, r;
        cin >> k >> l >> r;
        l--;
        r--;
        vector<int> pos;
        for (auto& d : divs(k)) {
            auto& v = h[d];
            auto it = lower_bound(v.begin(), v.end(), l);
            if (it != v.end() && *it <= r) {
                pos.push_back(*it);
            }
        }
        sort(pos.begin(), pos.end());
        int j = l;
        int ans = 0;
        for (auto& id : pos) {
            int cnt = id - j;
            ans += cnt * k;
            while (k % a[id] == 0) k /= a[id];
            j = id;
        }
        ans += (r + 1 - j) * k;
        cout << ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}