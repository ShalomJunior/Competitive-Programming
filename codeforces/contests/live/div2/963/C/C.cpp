#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int mx = *max_element(a.begin(), a.end());
    set<int> s;
    for (int i = 0; i < n; i++) {
        int len = mx - a[i];
        int q = len / (2 * k);
        while (2LL * k * q + a[i] <= mx - k) q++;
        s.insert(2LL * k * q + a[i]);
    }
    int r = 2 * n;
    for (int low = *s.begin(); r > 0; low++, r--) {
        int x = low + k - 1;
        int high = *prev(s.end());
        if (x >= high) {
            cout << high << endl;
            return;
        }
        s.erase(low);
        s.insert(low + 2 * k);
    }
    cout << -1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}