#include <bits/stdc++.h>
using namespace std;

void solve() {
    int root, n; cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (i == p[i]) root = i;
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i != root) adj[p[i]].push_back(i);
    }
    function<int(int)> dfs = [&](int r) {
        int ans = 0;
        for (auto& c : adj[r]) {
            ans += dfs(c);
        }
        return (ans ? ans : 1);
    };
    cout << dfs(root) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}