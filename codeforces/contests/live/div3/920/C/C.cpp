#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, f, a, b;
    cin >> n >> f >> a >> b;
    vector<int> x(n);
    for (auto& c : x) cin >> c;
    for (int i = 0; i < n; i++) {
        int on = (x[i] - (i ? x[i - 1] : 0)) * a;
        int off = b;
        f -= min(on, off);
        if (f <= 0) {
            cout << "NO" << endl;
            return;
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