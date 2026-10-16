#include <bits/stdc++.h>
using namespace std;

vector<int> g(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i * i < n) res.push_back(n / i);
        }
    }
    return res;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    unordered_map<int, map<int, int>> d;
    unordered_map<int, map<int, priority_queue<int, vector<int>, greater<int>>>> save;
    auto add = [&](int id, int di, int val) {
        if (id < 0) return;
        save[id][di].push(val);
        while (save[id].size() > 2) save[id][di].pop();
        };
    function<void(int, int)> dfs = [&](int r, int p) {
        auto ds = g(a[r]);
        for (auto& c : adj[r]) {
            if (c != p) {
                dfs(c, r);
            }
        }
        for (auto& di : ds) {
            int mx = 0;
            int curr = 1;
            while (!save[r][di].empty()) {
                int x = save[r][di].top();
                save[r][di].pop();
                mx = max(mx, x);
                curr += x;
            }
            d[r][di] = 1 + mx;
            if (p >= 0 && a[p] % di == 0) {
                add(p, di, 1 + mx);
            }
            if (di > 1) ans = max(ans, curr);
        }
        for (auto& c : adj[r]) d.erase(c);
        };
    dfs(0, -1);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}