#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int mx = *max_element(a.begin(), a.end());
    int tot = accumulate(a.begin(), a.end(), 0LL);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int base = max(mx * i, tot);
        int L = 0, R = 1e12;
        while (L < R) {
            int mid = (L + R) / 2;
            base <= mid * i ? R = mid : L = mid + 1;
        }
        int sup = L * i - tot;
        if (sup <= k) ans = i;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
