#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> a(m);
    map<int, int> h;
    for (auto& [w, x] : a) {
        cin >> x >> w;
        h[x] = 1 + h.size();
    }
    sort(a.begin(), a.end());
    int ans = 0;
    vector<int> px(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        ans += a[i].first;
        px[i] = a[i].second;
    }
    sort(px.begin(), px.end());
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << h[px[i]] << " " << h[px[2 * n - 1 - i]] << endl;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}