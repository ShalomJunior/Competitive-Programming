#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second 
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int a; cin >> a; a--;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    string s; cin >> s;
    vector<bool> vis(n);
    int cnt = 0;
    function<Mine(int)> dfs = [&](int r) {
        vis[r] = true;
        Mine ans = { 0, 0 };
        (s[r] == 'W') ? ans.F = 1 : ans.S = 1;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                auto p = dfs(c);
                ans.F += p.F;
                ans.S += p.S;
            }
        }
        if (ans.F && ans.F == ans.S)cnt++;
        return ans;
        };
    dfs(0);
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}