#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << pre[n - (x - y)] - pre[n - x] << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
