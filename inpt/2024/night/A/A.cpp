#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    map<pair<int, int>, int> h;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int cnt = 0;
        while (x % 2 == 0) {
            x /= 2;
            cnt++;
        }
        ans += h[{x, a[i] - cnt}]++;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}