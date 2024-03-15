#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6;
const int M = 1e5;
const int INF = 1e9;
vector<int> a;
vector<int> dp(N, INF);

void init() {
    a = { 1, 3, 6, 10, 15 };
    dp[0] = 0;
    for (int i = 1; i < N; i++) {
        for (auto& c : a) {
            if (i - c >= 0) {
                dp[i] = min(dp[i], 1 + dp[i - c]);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    if (n < N) {
        cout << dp[n] << endl;
        return;
    }
    int d = n - M;
    int q = d / 15;
    int ans = INF;
    for (int i = 0; i <= min(q, 10LL); i++) {
        int p = q - i;
        int s = p * 15;
        ans = min(ans, p + dp[n - s]);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin >> t;
    while (t--)solve();
}