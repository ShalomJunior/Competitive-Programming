#include <bits/stdc++.h>
using namespace std;

void solve() {
    int w, f, n; cin >> w >> f >> n;
    vector<int> a(n);
    int sum = 0;
    for (auto& c : a) cin >> c, sum += c;
    vector<int> dp(sum + 1);
    for (int i = 1; i <= n; i++) {
        vector<int> t = dp;
        for (int j = 0; j <= sum; j++) {
            if (j >= a[i - 1]) {
                t[j] = max(t[j], a[i - 1] + dp[j - a[i - 1]]);
            }
        }
        dp = t;
    }
    int L = 1, R = 1 + sum / max(f, w);
    while (L < R) {
        int mid = (L + R) / 2;
        int water = mid * w, fire = mid * f;
        int m = min(water, fire), M = max(water, fire);
        bool b = (water >= sum || fire >= sum ? true : M >= sum - dp[m]);
        b ? R = mid : L = mid + 1;
    }
    cout << L << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
