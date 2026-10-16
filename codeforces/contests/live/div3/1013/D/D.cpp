#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    auto check = [&](int mid) {
        int cnt = max(m / (mid + 1), 1LL);
        while ((cnt + 1) * (mid + 1) - 1 <= m) cnt++;
        int r = m - cnt * (mid + 1);
        int R = cnt * mid + max(r, 0LL);
        int tot = R * n;
        return tot >= k;
        };
    int L = 1, R = m;
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
    while (t--)solve();
}
