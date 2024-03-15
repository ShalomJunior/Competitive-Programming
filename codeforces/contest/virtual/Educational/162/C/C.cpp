#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), pre(n + 1), ones(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ones[i] = ones[i - 1] + (a[i] == 1);
        pre[i] = pre[i - 1] + a[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        int o = ones[r] - ones[l - 1];
        int cnt = len - o;
        cout << (l == r || pre[r] - pre[l - 1] < cnt + 2 * o ? "NO" : "YES") << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
