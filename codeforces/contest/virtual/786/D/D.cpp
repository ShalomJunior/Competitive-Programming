#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), g(n);
    for (auto& c : a) cin >> c;
    g[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        g[i] = min(a[i], g[i + 1]);
    }
    if (n & 1 && a[0] != g[0]) { cout << "NO" << endl; return; }
    int i = (n & 1) ? 1 : 0;
    for (; i < n - 2; i += 2) {
        if (a[i] > g[i + 2] || a[i + 1] > g[i + 2]) { cout << "NO" << endl; return; }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}