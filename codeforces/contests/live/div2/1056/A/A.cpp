#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    int w = n;
    int l = 0;
    int ans = 0;
    while (w > 1 || l > 1) {
        ans += w / 2 + l / 2;
        l = (l + 1) / 2 + w / 2;
        w = (w + 1) / 2;
    }
    cout << ans + 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
