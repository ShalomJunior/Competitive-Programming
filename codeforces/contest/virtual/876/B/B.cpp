#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> vec(n + 1);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        vec[a].push_back(b);
    }
    vector<int> f;
    for (int i = 1; i <= n; i++) {
        auto& v = vec[i];
        sort(v.rbegin(), v.rend());
        for (int j = 0; j < min(i, (int)v.size()); j++) {
            f.push_back(v[j]);
        }
    }
    sort(f.rbegin(), f.rend());
    int ans = 0;
    for (int i = 0; i < min(n, (int)f.size()); i++) {
        ans += f[i];
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}