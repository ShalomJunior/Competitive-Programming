#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
void solve() {
    int n, x, z;
    cin >> n >> x >> z;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<map<int, long long>> h(n);
    h[0][a[0] % x] = a[0];
    for (int i = 1; i < n; i++) {
        for (auto [j, v] : h[i - 1]) {
            h[i][(j + a[i]) % x] = v + a[i];
        }
    }
    int hs = z / x;
    if (hs * x < z) hs++;
    int d = hs * x - z;
    cout << "d = " << d << endl;
    long long m = INF;
    for (int i = 0; i < n; i++) {
        if (h[i].count(d)) {
            cout << "i = " << i << endl;
            m = min(m, h[i][d]);
        }
    }
    if (m == INF) {
        cout << -1 << endl;
        return;
    }
    long long sup = m - d;
    cout << hs + sup / x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}