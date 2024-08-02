#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n + 5);
    for (int i = 1; i <= n; i++) cin >> a[i];
    auto f = [&](int i) {
        return a[i] - c * i;
        };
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    sort(p.begin(), p.end(), [&](const int& i, const int& j) {
        return f(i) > f(j);
        });
    for (int j = 0; j < n; j++) {
        if (p[j] < 2) continue;
        if (a[1] + a[p[j]] < p[j] * c) {
            cout << "NO" << endl;
            return;
        }
        a[1] += a[p[j]];
    }
    cout << "YES" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}