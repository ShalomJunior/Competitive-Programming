#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> neb(n + 1);
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        neb[a].push_back(i);
        neb[i].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(neb[i].begin(), neb[i].end());
        neb[i].resize(unique(neb[i].begin(), neb[i].end()) - neb[i].begin());
    }

    vector<bool> vis(n + 1);
    function<pair<int, bool>(int, int)> dfs = [&](int r, int p) {
        vis[r] = true;
        pair<int, bool> ans = { 1, false };
        for (auto& c : neb[r]) {
            if (c == p) continue;
            else if (vis[c]) ans.S = true;
            else {
                auto p = dfs(c, r);
                ans.F += p.F;
                ans.S &= p.S;
            }
        }
        return ans;
    };
    int mn = 0, mx = 0, cycles = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            auto p = dfs(i, -1);
            if (p.S) cycles++;
            else mx++;
        }
    }
    if (mx) ++mn;
    mn += cycles; mx += cycles;
    cout << mn << " " << mx << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}