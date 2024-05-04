#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;

    unordered_map<int, int> mp;
    map<int, int> inv;
    for (int i = 1; i <= n; i++) {
        mp[i] = n + 1 - i;
        inv[n + 1 - i] = i;
    }

    int mn = 1, mx = n;

    vector<int> ans(n + 1, -1);
    for (int i = 0; i < m; i++) {
        int v; cin >> v;
        if (mp.find(v) == mp.end()) {
            int out = inv[mn];
            if (out <= n) ans[out] = i + 1;
            mp.erase(out); inv.erase(mn);
            mn = inv.begin()->first;
        }

        inv.erase(mp[v]);
        mp[v] = ++mx;
        inv[mx] = v;
    }

    for (int i = 1; i <= n;i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}