#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto check = [&](int mid) {
        int res = 0;
        vector<int> cnt(n, 1);
        vector<bool> vis(n);
        function<void(int)> dfs = [&](int r) {
            vis[r] = true;
            for (auto& c : adj[r]) {
                if (!vis[c]) {
                    dfs(c);
                    cnt[r] += cnt[c];
                }
            }
            if (cnt[r] >= mid) {
                res++;
                cnt[r] = 0;
            }
            };
        dfs(0);
        return res > k;
        };
    int L = 1, R = n / (k + 1);
    while (L < R) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            if (L == mid) check(R) ? L = R : R = L;
            else L = mid;
        }
        else R = mid - 1;
    }
    cout << L << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}