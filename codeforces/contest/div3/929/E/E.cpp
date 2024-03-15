#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    int q; cin >> q;
    while (q--) {
        int l, u;
        cin >> l >> u;
        auto it = upper_bound(pre.begin(), pre.end(), pre[l - 1] + u);
        int j = it - pre.begin();
        int ans = -INF;
        int r = -1;
        for (int k = max(j - 1, l); k <= min(j + 1, n); k++) {
            int s = pre[k] - pre[l - 1];
            int d = 0;
            if (s <= u + 1) {
                s = u - s;
                d = u * (u + 1) / 2 - s * (s + 1) / 2;
            }
            else {
                s -= (u + 1);
                d = u * (u + 1) / 2 - (s * (s + 1) / 2);
            }
            if (d > ans) {
                ans = d;
                r = k;
            }
        }
        assert(r != -1);
        cout << r << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
