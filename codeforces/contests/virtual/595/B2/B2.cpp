#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c, --c;
    vector<bool> vis(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        int j = i, cnt = 0;
        vector<int> pass;
        do {
            vis[j] = true;
            pass.push_back(j);
            cnt++;
            j = a[j];
        } while (j != i);
        for (auto& k : pass)ans[k] = cnt;
    }
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}