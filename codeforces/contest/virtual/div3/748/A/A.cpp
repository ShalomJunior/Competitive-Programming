#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, h; cin >> n >> h;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.rbegin(), a.rend());
    int r = a[0] + a[1];
    int ans = 2 * (h / r); h %= r;
    if (h) {
        if (h <= a[0]) ans++;
        else ans += 2;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}