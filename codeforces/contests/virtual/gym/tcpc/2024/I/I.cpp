#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, vector<int>> pos;
    int x = 0;
    pos[0].push_back(0);
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        x ^= a[i];
        if (!pos[x].empty()) {
            ans[i] = pos[x].back() + 1;
        }
        pos[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = max(ans[i], ans[i - 1]);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (ans[r] && ans[r] >= l ? "YES" : "NO") << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}