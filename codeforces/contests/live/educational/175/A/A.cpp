#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n <= 15) {
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            if (i % 3 == i % 5) ans++;
        }
        cout << ans;
    }
    else {
        int k = n / 15;
        int ans = k * 3;
        for (int i = k * 15; i <= n; i++) {
            if (i % 3 == i % 5)
                ans++;
        }
        cout << ans;
    }
    cout << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
