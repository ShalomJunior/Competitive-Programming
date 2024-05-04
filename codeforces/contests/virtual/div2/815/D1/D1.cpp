#include <bits/stdc++.h>
using namespace std;

const int N = 300;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    a.resize(min(N, n));
    n = a.size();
    vector<vector<int>> next(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((a[i] ^ j) < (a[j] ^ i)) {
                next[i].push_back(j);
            }
        }
    }
    vector<int> dp(n + 1, 1);
    for (int i = n - 1; i >= 0; i--) {
        int mx = 0;
        for (auto& c : next[i]) mx = max(mx, dp[c]);
        dp[i] += mx;
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}