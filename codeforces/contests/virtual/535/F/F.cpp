#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int len = 1, idx = 0;
    map<int, int> dp;
    dp[a[0]] = 1;
    for (int i = 1; i < n; i++) {
        dp[a[i]] = max(dp[a[i] - 1] + 1, dp[a[i]]);
        if (len < dp[a[i]]) {
            len = dp[a[i]];
            idx = i;
        }
    }
    cout << len << endl;
    vector<int> ans;
    int need = a[idx];
    while (idx >= 0 && ans.size() < len) {
        if (a[idx] == need) {
            ans.push_back(idx + 1);
            need--;
        }
        idx--;
    }
    for (int i = len - 1; i >= 0; i--) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}