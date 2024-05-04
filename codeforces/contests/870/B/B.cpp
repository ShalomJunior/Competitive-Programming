#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a)cin >> c;

    vector<int> c;
    int mid = n / 2 + (n & 1);
    for (int i = 0; i < mid; i++) {
        c.push_back(abs(a[i] - a[n - 1 - i]));
    }

    int g = c[0];
    for (int i = 0; i < mid; i++) {
        g = gcd(g, c[i]);
    }
    cout << g << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
