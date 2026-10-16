#include<bits/stdc++.h>
using namespace std;
void solve() {
    string a, b;
    cin >> a >> b;
    a = '#' + a;
    b = '#' + b;
    int n = a.length();
    int m = b.length();
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[n - 1][m - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
