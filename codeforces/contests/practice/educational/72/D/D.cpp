#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    map<pair<int, int>, int> ids;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        ids[{a, b}] = i;
    }
    bool cycle = false;
    vector<bool> vis(n);
    vector<int> ans(m);
    map<pair<int, int>, bool> done;
    function<void(int, int, int)> dfs = [&](int r, int p, int k) {
        vis[r] = true;
        cerr << r << "-> " << p << endl;
        cerr << "k=  " << k << endl;
        for (auto& c : adj[r]) {
            if (c != p) ans[ids[{c, r}]] = k;
            if (vis[c]) {
                if (c != p) cycle = true;
            }
            else dfs(c, r, k == 1 ? 2 : 1);
        }
        };

    for (int i = 0; i < n; i++) {
        if (!vis[i])
            dfs(i, i, 1);
    }
    if (cycle) {
        cerr << "in" << endl;
        for (auto& c : ans) cout << c << " ";
    }
    else {
        cout << 1 << endl;
        for (int i = 0; i < m; i++) cout << 1 << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
