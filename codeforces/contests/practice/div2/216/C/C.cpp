#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> all;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if (t == 2) {
            all.push_back(a);
            all.push_back(b);
        }
    }
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    vector<bool> vis(n);
    vector<int> par(n);
    vector<int> depth(n);
    function<void(int)> dfs = [&](int r) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                par[c] = r;
                depth[c] = depth[r] + 1;
                dfs(c);
            }
        }
        };
    dfs(0);
    sort(all.begin(), all.end(), [&](int a, int b) {
        return depth[a] > depth[b];
        });
    set<int> ans;
    vector<bool> done(n);
    for (auto& c : all) {
        if (done[c]) continue;
        ans.insert(c);
        int x = c;
        do {
            done[x] = true;
            x = par[x];
        } while (!done[x]);
        done[0] = true;
    }
    cout << ans.size() << endl;
    for (auto& c : ans) cout << c + 1 << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
