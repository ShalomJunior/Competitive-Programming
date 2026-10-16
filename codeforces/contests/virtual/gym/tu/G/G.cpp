#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<multiset<int>> t(m);
    for (int i = 0; i < n; i++) {
        int x;
        for (int j = 0; j < m; j++) {
            cin >> x;
            t[j].insert(x);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x = 0;
        for (int j = 0; j < m; j++) {
            auto it = t[j].lower_bound(x);
            if (it == t[j].end()) {
                cout << ans << endl;
                return;
            }
            x = *it;
            t[j].erase(it);
        }
        ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}