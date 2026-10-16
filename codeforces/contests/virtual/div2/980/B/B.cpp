#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    if (a[0] * n >= k) {
        cout << k << endl;
        return;
    }
    int ans = 0;
    int have = 0;
    auto work = [&](int j) {
        int can = a[j] - (j ? a[j - 1] : 0);
        int tot = can * (n - j);
        if (have + tot < k) {
            ans += tot + 1;
            have += tot;
        }
        else {
            ans += k - have;
            have = k;
        }
        };
    for (int i = 0; i < n && have < k; i++) work(i);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}