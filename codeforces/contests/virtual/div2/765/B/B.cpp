#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    map<int, vector<int>> h;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        h[x].push_back(i);
    }
    int ans = -1;
    for (auto& [k, v] : h) {
        int m = v.size();
        if (m > 1) {
            for (int i = 0; i < m - 1; i++) {
                ans = max(ans, n - (v[i + 1] - v[i]));
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}