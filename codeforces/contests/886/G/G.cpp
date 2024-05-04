#include <bits/stdc++.h>
#define int long long
using namespace std;

int go(map<int, int>& a) {
    int ans = 0;
    for (auto& [k, v] : a) {
        ans += v * (v - 1);
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    map<int, int> a, b, c, d;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[y - x]++;
        b[y + x]++;
        c[x]++;
        d[y]++;
    }
    int ans = go(a) + go(b) + go(c) + go(d);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}