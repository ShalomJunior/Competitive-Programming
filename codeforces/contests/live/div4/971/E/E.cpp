#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, k;
    cin >> n >> k;
    int tot = n * (k + k + n - 1) / 2;
    int L = 1, R = n;
    auto f = [&](int mid) {
        int x = mid * (k + k + mid - 1) / 2;
        int y = tot - x;
        return x - y;
        };
    while (L < R) {
        int mid = (L + R) / 2;
        if (f(mid) <= 0) {
            if (L == mid) f(R) <= 0 ? L = R : R = L;
            else L = mid;
        }
        else {
            R = mid - 1;
        }
    }
    int ans = INF;
    ans = min(ans, abs(f(L)));
    ans = min(ans, f(L + 1));
    cout << ans << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
