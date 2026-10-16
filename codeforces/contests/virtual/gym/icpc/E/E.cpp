#include <bits/stdc++.h>
using namespace std;

const int S = 2e4;
void solve() {
    while (true) {
        int t;
        cin >> t;
        if (t == 0) return;
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& c : a) cin >> c;
        int s = accumulate(a.begin(), a.end(), 0);
        vector<vector<bool>> dp(n + 1, vector<bool>(s + 1));
        dp[n][0] = true;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];
            for (int j = 0; j <= s; j++) {
                if (dp[i + 1][j]) {
                    dp[i][j + a[i]] = true;
                }
            }
        }
        int tot = min(t, s);
        while (!dp[0][tot]) tot--;
        int j = tot;
        for (int i = 0; i < n; i++) {
            if (j - a[i] >= 0 && dp[i + 1][j - a[i]]) {
                cout << a[i] << " ";
                j -= a[i];
            }
        }
        cout << tot << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}