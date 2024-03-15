#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int p; cin >> p; --p;
        adj[p].push_back(i);
    }
    vector<int> depth(n);
    function<void(int)> dfs = [&](int r) {
        for (auto& c : adj[r]) {
            depth[c] = depth[r] + 1;
            dfs(c);
        }
        };
    dfs(0);
    int D = *max_element(depth.begin(), depth.end());
    map<int, int> cnt;
    for (int i = 0; i < n; i++) cnt[depth[i]]++;
    int ans = 0, M = 0;
    for (auto& [k, v] : cnt) {
        cout << "k  " << k << " v " << v << endl;
        if (v > 1) ans += v;
        M = max(M, v);
    }
    if (cnt[D] == 1 && M > 1) {
        cout << "add" << endl;
        ans++;
    }
    cout << ans << endl;
    cout << ans / 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
