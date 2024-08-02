#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        h[a[i]]++;
    }
    vector<int> o;
    for (auto& [k, _] : h) o.push_back(k);
    int z = o.size();
    int ans = 0;
    for (int id = 0; id < z; id++) {
        int k = o[id];
        int v = h[k];
        for (int i = 0; i <= v && i * k <= m; i++) {
            int r = m - i * k;
            int j = (h.count(k + 1) ? min(r / (k + 1), h[k + 1]) : 0);
            ans = max(ans, i * k + j * (k + 1));
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
