#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 64;
const int INF = 5e18;
void solve() {
    int n, x; cin >> n >> x;
    int L = n, R = INF;
    auto go = [&](int mid) {
        int ans = 0;
        for (int i = N - 1; i >= 0; i--) {
            int mask = 1LL << i;
            if ((mid & mask) ^ (n & mask)) break;
            if (mid & mask) ans |= mask;
        }
        return ans;
        };
    while (L + 1 <= R) {
        int mid = (L + R) / 2;
        go(mid) <= x ? R = mid : L = mid + 1;
    }
    if (go(L == x)) cout << L;
    else if (go(R) == x) cout << R;
    else cout << -1;
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}