#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (abs(n - m) > k || max(n, m) < k) {
        cout << -1 << endl;
        return;
    }
    string ans;
    for (int i = 0; i + k <= min(n, m); i += k) {
        ans += string(k, '0');
        ans += string(k, '1');
    }
    int q = min(n, m) / k;
    n -= q * k;
    m -= q * k;
    if (n >= k) {
        ans += string(k, '0');
        n -= k;
    }
    if (m >= k) {
        ans = string(k, '1') + ans;
        m -= k;
    }
    while (n || m) {
        if (ans.empty() || ans[0] == '0') {
            ans = string(m, '1') + ans;
            m = 0;
        }
        else {
            ans = string(n, '0') + ans;
            n = 0;
        }
        if (ans.empty() || ans.back() == '0') {
            ans += string(m, '1');
            m = 0;
        }
        else {
            ans += string(n, '0');
            n = 0;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
