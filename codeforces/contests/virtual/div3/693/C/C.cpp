#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<long long> dp(n);
    for (int i = n - 1; i >= 0; i--) {
        dp[i] += a[i];
        dp[i] += (i + a[i] < n ? dp[i + a[i]] : 0);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}