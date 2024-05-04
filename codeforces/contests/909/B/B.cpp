#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

int get(vector<int>& pre, int d) {
    int m = pre[d - 1], M = pre[d - 1];
    for (int i = 2 * d - 1; i < pre.size(); i += d) {
        m = min(m, pre[i] - pre[i - d]);
        M = max(M, pre[i] - pre[i - d]);
    }
    return M - m;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n), pre(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i] = a[i] + (i ? pre[i - 1] : 0);
    }
    int ans = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i) continue;
        int d1 = i, d2 = n / i;
        ans = max({ ans, get(pre, d1), get(pre, d2) });
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
