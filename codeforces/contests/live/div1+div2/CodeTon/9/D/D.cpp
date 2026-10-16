#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    set<int> s;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        set<int> r;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                int d1 = j;
                int d2 = i / j;
                r.insert(ans[d1]);
                r.insert(ans[d2]);
                s.erase(ans[d1]);
                s.erase(ans[d2]);
            }
        }
        if (s.empty()) {
            cout << -1 << endl;
            return;
        }
        ans[i] = *prev(s.end());
        for (auto& c : r) s.insert(c);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}