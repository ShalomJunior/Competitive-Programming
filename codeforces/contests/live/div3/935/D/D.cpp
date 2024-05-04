#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (auto& c : a)cin >> c;
    for (auto& c : b)cin >> c;
    vector<int> x(n + 1), y(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i] + min(x[i + 1], y[i + 1]);
        y[i] = b[i] + min(x[i + 1], y[i + 1]);
    }
    int ans = *min_element(x.begin(), x.begin() + m);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
