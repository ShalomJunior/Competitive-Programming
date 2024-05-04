#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    vector<int> pre(n), m(n);
    pre[0] = a[0];
    m[0] = b[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + a[i];
        m[i] = max(m[i - 1], b[i]);
    }
    int ans = 0;
    for (int i = 0; i < min(n, k); i++) {
        ans = max(ans, pre[i] + m[i] * (k - i - 1));
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
