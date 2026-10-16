#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;
const int MOD = 998244353;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, -INF);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> b(n + 1, -INF);
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<int> x(n + 1), y(n + 1);
    x[0] = y[0] = 1;

    for (int i = 1; i <= n; i++) {
        if (min(a[i - 1], b[i - 1]) > min(a[i], b[i])) {
            cout << 0 << endl;
            return;
        }
        if (max(a[i - 1], b[i - 1]) > max(a[i], b[i])) {
            cout << 0 << endl;
            return;
        }
        if (a[i] >= a[i - 1] && b[i] >= b[i - 1]) {
            x[i] += x[i - 1];
            y[i] += y[i - 1];

        }
        if (a[i] >= b[i - 1] && b[i] >= a[i - 1]) {
            x[i] += y[i - 1];
            y[i] += x[i - 1];
        }

    }
    cout << x[n] + y[n] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
