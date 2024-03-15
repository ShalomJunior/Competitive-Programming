#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; string s;
    cin >> n >> k >> s;
    vector<int> id;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') id.push_back(i);
    }
    if (id.empty()) {
        cout << 1 + (n - 1) / (k + 1) << endl;
        return;
    }
    int m = id.size(), ans = 0;
    for (int i = 0; i < m; i++) {
        int moves = (id[i] - (i ? id[i - 1] : 0));
        int add = moves / (k + 1);
        ans += moves / (k + 1);
        if (i > 0 && add) ans--;
        if (i == m - 1 && id[i] != n - 1) ans += (n - 1 - id[i]) / (k + 1);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}