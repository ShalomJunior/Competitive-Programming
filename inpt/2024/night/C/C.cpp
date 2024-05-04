#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) {
        cin >> c;
        c = abs(c);
    }
    int s = accumulate(a.begin(), a.end(), 0LL);
    vector<bool> dp(N), temp(N);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        temp = dp;
        for (int j = 0; j <= s; j++) {
            if (temp[j]) {
                dp[j + a[i]] = true;
            }
        }
    }
    cout << (s % 2 == 0 && dp[s / 2] ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}