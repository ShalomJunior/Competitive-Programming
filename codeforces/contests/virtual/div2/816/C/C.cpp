#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + (a[i] == a[i - 1] ? 0 : i) + 1;
    }
    int tot = accumulate(dp.begin(), dp.end(), 0LL);
    while (m--) {
        int i, x;
        cin >> i >> x;
        --i;
        if (a[i] != x) {
            if ((i == 0 || a[i - 1]) == x && (i == n - 1 || a[i + 1] == x)) {

            }
            if (i) {
                int l = i;
                int r = n - i;
                if (a[i - 1] == x) {
                    tot -= l * r;
                }
                else if (a[i - 1] == a[i]) {
                    tot += l * r;
                }
            }
            if (i != n - 1) {
                cerr << "in" << endl;
                int l = i + 1;
                int r = n - (i + 1);
                if (a[i + 1] == x) {
                    tot -= l * r;
                }
                else if (a[i + 1] == a[i]) {
                    tot += l * r;
                }
                cerr << "out" << endl;
            }
        }
        cout << tot << endl;
        a[i] = x;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}