#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int mx = *max_element(a.begin(), a.end());
    int L = 1;
    for (int i = 0; i < n; i++) {
        L = lcm(L, a[i]);
        if (L > mx) {
            cout << n << endl;
            return;
        }
    }
    set<int> d;
    for (int i = 1; i * i <= L; i++) {
        if (L % i == 0) {
            d.insert(i);
            d.insert(L / i);
        }
    }
    for (auto& c : a) d.erase(c);
    map<int, int> dp;
    map<int, int> temp;
    dp[1] = 0;
    for (int i = 0; i < n; i++) {
        temp = dp;
        for (auto& [k, v] : dp) {
            int l = lcm(k, a[i]);
            if (L % l == 0)
                dp[l] = max(dp[l], temp[k] + 1);
        }
    }
    int ans = 0;
    for (auto& c : d) ans = max(ans, dp[c]);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
