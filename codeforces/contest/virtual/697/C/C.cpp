#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m, n, k; cin >> m >> n >> k;
    vector<int> a(k), b(k);
    map<int, int> x, y;
    for (auto& c : a) { cin >> c; x[c]++; }
    for (auto& c : b) { cin >> c; y[c]++; }
    long long ans = 0;
    for (int i = 0; i < k; i++) {
        ans += k - 1 - i - --x[a[i]] - --y[b[i]];
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}