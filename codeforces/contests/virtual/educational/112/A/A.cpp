#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100;
const int INF = 1e9;
vector<int> dp(N, INF);
void init() {
    dp[0] = 0;
    map<int, int> h;
    h[6] = 15;
    h[8] = 20;
    h[10] = 25;
    vector<int> cost = { 10, 15, 25 };
    for (int i = 1; i < N; i++) {
        for (auto& [k, v] : h) {
            int j = max(i - k, 0LL);
            dp[i] = min(dp[i], v + dp[j]);
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
    int q = (n - N) / 10;
    while (n - q * 10 >= N) q++;
    int ans = q * 25 + dp[n - q * 10];
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin >> t;
    while (t--) solve();
}
