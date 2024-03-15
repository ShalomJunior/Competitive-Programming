#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& c : v)cin >> c;

    sort(v.begin(), v.end());

    if (v[0] != 1) {
        cout << "NO" << endl;
        return;
    }

    vector<int> dp(n);
    function<int(int, int)> can = [&](int val, int pos) {
        cout << val << " " << pos << endl;
        if (val == 0) return 1;
        if (pos < 0) return 0;

        if (dp[pos]) return 1;
        bool ans = 0;
        for (int i = pos; i >= 0; i--) {
            ans |= can(val - v[i], i - 1);
            if (ans) {
                dp[pos] = 1;
                return 1;
            }
        }
        cout << "Here " << dp[pos] << endl;
        return dp[pos];
    };

    for (int i = n - 1; i > 0; i--) {
        if (!can(v[i], i - 1)) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}