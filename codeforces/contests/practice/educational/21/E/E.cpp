#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> c1, c2, c3;
    for (int i = 0; i < n; i++) {
        int w, c;
        cin >> w >> c;
        if (w == 1) c1.push_back(c);
        else if (w == 2) c2.push_back(c);
        else c3.push_back(c);
    }
    sort(c1.rbegin(), c1.rend());
    sort(c2.rbegin(), c2.rend());
    sort(c3.rbegin(), c3.rend());
    int z1 = c1.size();
    int z2 = c2.size();
    int z3 = c3.size();
    while (z1++ < m) c1.push_back(0);
    vector<int> dp(m + 1);
    int i = 0;
    int j = 0;
    for (int k = 1; k <= m; k++) {
        int ndp = dp[k - 1] + c1[i];
        i++;
        while (j < z2 && i >= 2) {
            int add = c2[j] - c1[i - 1] - c1[i - 2];
            if (add > 0) {
                ndp += add;
                j++;
                i -= 2;
            }
            else break;
        }
        dp[k] = ndp;
    }
    int S = 0;
    int ans = dp[m];
    for (int k = 0; k < z3 && m - 3 * (k + 1) >= 0; k++) {
        S += c3[k];
        ans = max(ans, S + dp[m - 3 * (k + 1)]);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
