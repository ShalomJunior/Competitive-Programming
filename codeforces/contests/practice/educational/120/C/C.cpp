#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.rbegin(), a.rend());
    int mn = a.back();
    int tot = accumulate(a.begin(), a.end(), 0LL);
    auto check = [&](int mid) {
        int b = mid;
        int ans = tot - mid;
        int s = 0;
        for (int i = 0; i < n - 1 && b; i++) {
            s += a[i];
            b--;
            ans = min(ans, tot - s - mn + (i + 2) * (mn - b));
        }
        return ans <= k;
        };
    int L = 0, R = 1e10;
    while (L < R) {
        int mid = (L + R) / 2;
        check(mid) ? R = mid : L = mid + 1;
    }
    cout << R << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}