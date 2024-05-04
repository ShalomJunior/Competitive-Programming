#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    int j = 1;
    int m = 0;
    while (true) {
        m += j;
        int need = m * (m + 1) / 2;
        if (n >= need) {
            ans++;
            n -= need;
        }
        else break;
        j *= 2;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}