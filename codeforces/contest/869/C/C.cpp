#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (auto& c : a)cin >> c;
    int dp[n], last;
    last = dp[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            dp[i] = dp[i - 1] + 1;
            last = 1;
        }
        else {
            last++;
            dp[i] = dp[i - 1] + (last <= 2 ? 1 : 0);
        }
    }
    int cnt = 0;
    while (q--) {
        cnt++;
        int l, r; cin >> l >> r;
        --l, --r;
        if (!l)
            cout << dp[r];
        else if (a[l] > a[l - 1])
            cout << dp[r] - dp[l - 1];
        else {
            int should = 1 + (l + 1 <= r && a[l] >= a[l + 1] ? 1 : 0);
            int trail = 1 + (l - 2 >= 0 && a[l - 2] >= a[l - 1] ? 1 : 0);
            cout << dp[r] - dp[l - 1] + (trail >= 2 ? should : should - 1);
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
