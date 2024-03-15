#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
long long dp[N];

void solve() {
    int n; cin >> n;
    cout << dp[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[1] = 0;
    for (int i = 3; i < N; i++) {
        dp[i] = dp[i - 2] + (i / 2) * (4LL * (i - 1));
    }
    int t; cin >> t;
    while (t--)solve();
}