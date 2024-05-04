#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int x = 0;
    while (x < n && a[x] == a[0]) x++;
    int y = 0;
    while (y < n && a[n - 1 - y] == a[n - 1]) y++;
    int u = max(x, y);
    int ans = 0;
    while (u < n) {
        ans++;
        u *= 2;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}