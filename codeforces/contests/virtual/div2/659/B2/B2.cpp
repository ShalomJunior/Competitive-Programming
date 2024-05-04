#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++) cin >> d[i];
    vector<int> x(n + 1, -1), y(n + 1, -1);
    x[0] = 0, y[0] = k + 1;
    for (int i = 1; i <= n; i++) {
        if (d[i] > l) {
            cout << "NO" << endl;
            return;
        }
        int lim = min(l - d[i], k);
        if (x[i - 1] == -1) {}
        else {
            if (x[i - 1] + 1 <= lim) x[i] = x[i - 1] + 1;
        }
        if (y[i - 1] == -1) {}
        else {
            if (y[i - 1])x[i] = 0;
            else if (lim)x[i] = 1;
            if (y[i - 1]) y[i] = min(y[i - 1] - 1, lim);
        }
        if (x[i] == -1 && y[i] == -1) {
            cout << "NO" << endl;
            return;
        }

        if (lim == k) {
            x[i] = 0;
            y[i] = k + 1;
        }
    }
    cout << "YES" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}