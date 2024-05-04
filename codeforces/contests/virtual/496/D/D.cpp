#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<int> pref(n);
    vector<vector<int>> id(3);
    for (int i = 0; i < n; i++) {
        pref[i] = (s[i] - '0') + (i ? pref[i - 1] : 0);
        id[pref[i] % 3].push_back(i);
    }
    vector<int> match(n, -1);
    for (int i = 0; i < n; i++) {
        if ((s[i] - '0') % 3 == 0) { match[i] = i; continue; }
        int r = pref[i] % 3;
        auto it = lower_bound(id[r].begin(), id[r].end(), i);
        if (it != id[r].begin()) match[i] = 1 + *(it - 1);
        else if (!r) match[i] = 0;
    }
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        int j = match[i];
        if (j != -1) dp[i] = 1 + (j ? dp[j - 1] : 0);
        dp[i] = max(dp[i], i ? dp[i - 1] : 0);
    }
    cout << dp[n - 1] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}