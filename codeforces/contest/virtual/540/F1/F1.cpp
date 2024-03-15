#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> c(n);
    int red = 0, blue = 0;
    for (auto& x : c) {
        cin >> x;
        if (x == 1) red++;
        if (x == 2) blue++;
    }
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int res = 0;
    vector<bool> vis(n);
    function <Mine(int)> Dfs = [&](int r) {
        vis[r] = true;
        Mine ans = { 0, 0 };
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                Mine p = Dfs(c);
                if ((p.F == red && !p.S) || (!p.F && p.S == blue)) res++;
                ans.F += p.F;
                ans.S += p.S;
            }
        }
        if (c[r] == 1) ans.F++;
        if (c[r] == 2) ans.S++;
        return ans;
        };
    Dfs(0);
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}