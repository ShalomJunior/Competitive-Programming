#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> m(n), c(k);
    for (auto& u : m) cin >> u;
    for (auto& u : c) cin >> u;
    sort(m.begin(), m.end());
    int L = 1, R = n;
    vector<vector<int>> ans;
    auto go = [&](int mid) {
        vector<vector<int>> a(mid);
        int i = n - 1;
        int j = 0;
        int mis = 0;
        while (i >= 0 && mis <= mid) {
            while (i >= 0 && (int)a[j].size() < c[m[i] - 1]) {
                a[j].push_back(m[i--]);
                mis = 0;
            }
            mis++;
            j = (j + 1) % mid;
        }
        if (i < 0 && (ans.empty() || ans.size() > mid)) ans = a;
        return i < 0;
        };
    while (L < R) {
        int mid = (L + R) / 2;
        go(mid) ? R = mid : L = mid + 1;
    }
    go(L);
    cout << ans.size() << endl;
    for (auto& v : ans) {
        cout << v.size() << " ";
        for (auto& u : v) cout << u << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}