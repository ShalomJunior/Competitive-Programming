#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<vector<int>> adj(n);
    string ans(n, '0');
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (a[u] == a[v]) {
            ans[a[u] - 1] = '1';
        }
    }
    for (int i = 0; i < n; i++) {
        map<int, vector<int>> h;
        for (auto& c : adj[i]) h[a[c]].push_back(c);
        for (auto& [k, v] : h) {
            if (v.size() > 1) {
                ans[k - 1] = '1';
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
