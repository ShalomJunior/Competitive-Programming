#include <bits/stdc++.h>
#define ll long long

using namespace std;

void dbg(vector<vector<ll>>& v) {
    int m = v.size();
    int n = v[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<ll>> v(m, vector<ll>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[j][i];
        }
    }

    ll ans = 0;
    for (int i = 0; i < m; i++) {
        sort(v[i].begin(), v[i].end());
        vector<ll> dp(n);
        dp[0] = 0;
        for (int j = 1; j < n; j++) {
            dp[j] = j * (v[i][j] - v[i][j - 1]) + dp[j - 1];
        }
        ans += accumulate(dp.begin(), dp.end(), (ll)0);
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}