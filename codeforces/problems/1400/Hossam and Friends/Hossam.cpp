#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    unordered_map<int, vector<int>> h;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        h[a].push_back(b);
        h[b].push_back(a);
    }

    int ans = 0;
    int cnt = 0, start = 1;
    for (int i = 1; i <= n; i++) {
        sort(h[i].begin(), h[i].end());
        auto L = lower_bound(h[i].begin(), h[i].end(), start);
        auto R = lower_bound(h[i].begin(), h[i].end(), i);
        if (L == R) {
            cnt++;
            continue;
        }
        R--;
        int del = i - 1 - *R;
        ans += cnt * (cnt + 1) / 2 - del * (del + 1) / 2;
        cnt = i - *R; start = *R + 1;
    }
    ans += cnt * (cnt + 1) / 2;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}