#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.rbegin(), a.rend());
    vector<int> pre(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + a[i];
    int ans = -INF;
    for (int i = 0; i <= k; i++) {
        if (i == n) {
            ans = max(ans, 0);
            continue;
        }
        int s = pre[n - 1] - (i ? pre[i - 1] : 0);
        int r = (i + x - 1 < n ? pre[i + x - 1] : pre[n - 1]);
        int l = (i ? pre[i - 1] : 0);
        s -= (r - l) * 2;
        ans = max(ans, s);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
