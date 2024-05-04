#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    map<int, int> h;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        h[a - i]++;
    }
    int ans = 0;
    for (auto& [k, cnt] : h) {
        ans += cnt * (cnt - 1) / 2;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}