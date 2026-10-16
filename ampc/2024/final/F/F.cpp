#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int N = 2 * n - 1;
    int s = n - 2;
    auto g = [&](char& l, int& u) {
        if (l == 's') u += 1;
        if (l == 'p') u += 1 + s;
        };
    vector<vector<int>> adj(N);
    for (int i = 0; i < 2 * (s + 1); i++) {
        char l1, l2;
        int u1, u2;
        cin >> l1 >> u1 >> l2 >> u2;
        g(l1, u1);
        g(l2, u2);
        adj[u1].push_back(u2);
        adj[u2].push_back(u1);
    }
    int k;
    cin >> k;
    vector<int> ids(k);
    for (auto& c : ids) {
        cin >> c;
        c += 1 + s;
    }
    vector<bool> vis(N);
    vector<int> cnt(N);
    vector<int> down(N);
    vector<int> dp(N);
    for (int i = s + 1; i < N; i++) cnt[i] = 1;
    for (auto& c : ids) down[c] = 1;
    function<void(int) > dfs = [&](int r) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                dp[c] = dp[r] + 1;
                dfs(c);
                cnt[r] += cnt[c];
                down[r] += down[c];
            }
        }
        };
    dfs(0);
    if (down[0] == n) {
        cout << "AGI is a myth" << endl;
        return;
    }
    else {
        int ans = -1;
        int d = 1e9;
        for (int i = 1; i <= s; i++) {
            if (cnt[i] == down[i]) {
                if (dp[i] < d) {
                    ans = i - 1;
                    d = dp[i];
                }
            }
        }
        assert(ans != -1);
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}