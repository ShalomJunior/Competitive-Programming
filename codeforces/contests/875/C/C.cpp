#include <bits/stdc++.h>
#define Mine pair<int,int>
using namespace std;

void solve() {
    int n; cin >> n;
    map<Mine, int> idx;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        if (a > b)swap(a, b);
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        idx[{a, b}] = i;
    }
    vector<bool> vis(n);
    vector<int> ans(n); ans[0] = 1;
    int M = 0;
    function<void(int, int)> dfs = [&](int r, int p) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                if (idx[{min(p, r), max(p, r)}] > idx[{min(r, c), max(r, c)}]) ans[c] = ans[r] + 1;
                else ans[c] = ans[r];
                dfs(c, r);
            }
        }
        M = max(M, ans[r]);
        };
    dfs(0, -1);
    cout << M << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}