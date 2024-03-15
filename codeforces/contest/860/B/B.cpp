#include <bits/stdc++.h>

using namespace std;

void solve() {
    int m; cin >> m;
    unordered_map<int, int> mp;
    for (int i = 0; i < m; i++) {
        int n; cin >> n;
        for (int j = 0; j < n; j++) {
            int k; cin >> k;
            mp[k] = i + 1;
        }
    }

    int cnt = 0;
    vector<int> ans(m + 1);
    vector<bool> done(m + 1);
    for (auto& [id, d] : mp) {
        if (!done[d]) {
            ans[d] = id;
            done[d] = true;
            cnt++;
        }
    }

    if (cnt < m) {
        cout << -1 << endl;
        return;
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}