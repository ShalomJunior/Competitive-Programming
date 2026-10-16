#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i] - k;
    }
    auto x = b;
    sort(x.begin(), x.end());
    if (x[0] > 0) {
        int g = b[0];
        for (auto& c : b) g = __gcd(g, c);
        int ans = 0;
        for (auto& c : b) ans += c / g - 1;
        cout << ans;
    }
    else if (x.back() < 0) {
        int g = -b[0];
        for (auto& c : b) g = __gcd(g, -c);
        int ans = 0;
        for (auto& c : b) ans += -c / g - 1;
        cout << ans;
    }
    else if (x[0] == 0 && x.back() == 0) {
        cout << 0;
    }
    else {
        cout << -1;
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
