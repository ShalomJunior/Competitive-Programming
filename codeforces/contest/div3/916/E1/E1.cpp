#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n), p(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        return a[i] + b[i] > a[j] + b[j];
        });
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        i & 1 ? ans -= (b[p[i]] - 1) : ans += a[p[i]] - 1;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
