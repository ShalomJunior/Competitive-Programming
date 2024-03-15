#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> c(n);
    for (auto& x : c) cin >> x;
    set<int> have;
    for (int i = 0; i < k; i++) {
        int a; cin >> a;
        have.insert(--a);
    }
    for (int i = 0; i < n; i++) {
        int ans = 0;
        int m; cin >> m;
        if (m) {
            for (int j = 0; j < m; j++) {
                int p; cin >> p; --p;
                if (!have.count(p)) ans += c[p];
            }
        }
        else ans += c[i];
        ans = min(ans, c[i]);
        cout << (have.count(i) ? 0 : ans) << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}