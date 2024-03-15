#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, d; cin >> n >> m >> d;

    unordered_map<int, int> mp;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        mp[p[i]] = i + 1;
    }

    vector<int> a(m), idx(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        idx[i] = mp[a[i]];
    }

    int ans = INT_MAX;
    for (int i = 0; i < m - 1; i++) {
        if (idx[i] > idx[i + 1] || idx[i] + d < idx[i + 1]) {
            cout << 0 << endl;
            return;
        }
        ans = min(ans, idx[i + 1] - idx[i]);
    }

    for (int i = 0; i < m - 1; i++) {
        int x = idx[i], y = idx[i + 1];
        int plus = x + d + 1 - y;
        if (x - 1 + n - y >= plus) {
            ans = min(ans, plus);
        }
    }

    cout << ans << endl;
}


int main() {
    int t; cin >> t;
    while (t--)solve();
}