#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, x, y; cin >> n >> x >> y;
    string a, b; cin >> a >> b;
    vector<int> bad;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) bad.push_back(i);
    }
    int m = bad.size();
    if (m & 1) {
        cout << -1 << endl;
        return;
    }
    if (m == 2) {
        if (bad[0] + 1 == bad[1]) {
            if (n == 2) cout << x;
            else {
                cout << min(x, 2 * y);
            }
        }
        else cout << y;
    }
    else cout << (m / 2) * y;
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}