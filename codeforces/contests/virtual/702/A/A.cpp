#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int x = min(a[i], a[i + 1]);
        int y = max(a[i], a[i + 1]);
        for (int i = 2 * x; i < y; i *= 2) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}