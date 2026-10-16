#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    int z = 1;
    function<void(int)> go = [&](int len) {
        if (len & 1) {
            int start = (len + 1) / 2;
            int end = n - len / 2;
            ans += z * (start + end) / 2;
        }
        z *= 2;
        if (len / 2 >= k) go(len / 2);
        };
    go(n);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}

