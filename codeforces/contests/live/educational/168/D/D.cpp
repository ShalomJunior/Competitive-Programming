#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> p(n);
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int r;
        cin >> r;
        r--;
        p[i] = r;
        adj[i].push_back(r);
        adj[r].push_back(i);
    }
    auto check = [&](int mid) {
        cerr << "mid = " << mid << endl;
        bool res = true;
        int sup = 0;
        vector<bool> vis(n);
        function<void(int, int)> dfs = [&](int r, int mn) {
            vis[r] = true;
            int next = max(mn - a[r])
                int next = mn + max(mn - a[r], 0LL);
            int down = 0;
            for (auto& c : adj[r]) {
                if (!vis[c]) {
                    down++;
                    dfs(c, next);
                }
            }
            if (down == 0) {
                res &= (a[r] >= mn);
                cerr << a[r] << " ŋ " << mn << endl;
            }
            };
        dfs(0, mid);
        return res;
        };
    int L = 0, R = *max_element(a.begin(), a.end());
    while (L < R) {
        cerr << L << " -> " << R << endl;
        int mid = (L + R) / 2;
        if (check(mid)) {
            if (L == mid) check(R) ? L = R : R = L;
            else L = mid;
        }
        else R = mid - 1;
    }
    cout << L << " # " << R << endl;
    cerr << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}