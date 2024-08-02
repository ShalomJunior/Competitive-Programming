#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int mx = 0;
    map<int, int> dp;
    map<int, int> last;
    map<int, vector<pair<int, int>>> h;
    for (auto& c : a) last[c] = -1;
    for (int i = 0; i < n; i++) {
        if (last[a[i]] != -1)
            dp[i] = dp[last[a[i]] - 1] + 1;
        if (dp[i - 1] <= dp[i]) {
            h[dp[i]].push_back({ last[a[i]], i });
        }
        else {
            dp[i] = dp[i - 1];
        }
        mx = max(mx, dp[i]);
        last[a[i]] = i;
    }
    if (mx == 0) {
        cout << -1 << endl;
        return;
    }
    cout << mx << endl;
    int end = n;
    vector<pair<int, int>> seg;
    for (int i = mx; i > 0; i--) {
        auto v = h[i];
        sort(v.begin(), v.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second != b.second) return a.second < b.second;
            return a.first < b.first;
            });
        while (v.back().second >= end) v.pop_back();
        assert(!v.empty());
        seg.push_back(v.back());
        end = v.back().first;
    }
    sort(seg.begin(), seg.end());
    vector<pair<int, int>> ans;
    int j = 0;
    for (auto& [l, r] : seg) {
        ans.push_back({ min(l + 1, j + 1), r + 1 });
        j = r + 1;
    }
    if (ans.back().second != n) ans.back().second = n;
    for (auto& [l, r] : ans) cout << l << " " << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
