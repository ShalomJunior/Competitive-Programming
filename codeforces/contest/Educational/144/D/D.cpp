#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i] - x;
    }
    vector<int> pre(n);
    pre[0] = max(pre[0], b[0]);
    for (int i = 1; i < n; i++) {
        pre[i] = max({ pre[i], b[i], b[i] + pre[i - 1] });
    }
    vector<int> suf(n);
    suf[n - 1] = max(suf[n - 1], a[n - 1] - x);
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = max({ suf[i], b[i], b[i] + suf[i + 1] });
    }
    int ans = 0;
    for (int i = 0; i <= n - k; i++) {
        int cnt = 0;
        for (int q = 0; q < k; q++) {
            cnt += a[i + q] + x;
        }
        cout << cnt << endl;
        if (i) cout << "#" << pre[i - 1] << endl;
        if (i + k < n) cout << "->" << suf[i + k] << endl;
        //int big = max(i ? pre[i - 1] : 0, i + k < n ? suf[i + k] : 0);
        ans = max(ans, cnt + (i ? pre[i - 1] : 0) + (i + k < n ? suf[i + k] : 0));
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}