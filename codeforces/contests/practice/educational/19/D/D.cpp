#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> adj(n);
    vector<int> p(n, -1);
    for (int i = 0; i < n; i++) {
        auto& [l, r] = adj[i];
        cin >> a[i] >> l >> r;
        if (l > 0) {
            l--;
            p[l] = i;
        }
        if (r > 0) {
            r--;
            p[r] = i;
        }
    }
    int root = 0;
    while (p[root] != -1) root++;
    set<int> S(a.begin(), a.end());
    function<void(int, int, int)> dfs = [&](int s, int l, int r) {
        if (s == -1) return;
        if (l <= a[s] && a[s] <= r) S.erase(a[s]);
        if (a[s] > l) {
            dfs(adj[s].first, l, min(a[s] - 1, r));
        }
        if (a[s] < r) {
            dfs(adj[s].second, max(a[s] + 1, l), r);
        }
        };
    dfs(root, 0, INF);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (S.count(a[i])) {
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
