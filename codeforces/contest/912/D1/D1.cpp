#include <bits/stdc++.h>
using namespace std;

const int N = 62;
void solve() {
    int n, q; cin >> n >> q;
    vector<long long> a(n);
    for (auto& c : a) cin >> c;
    while (q--) {
        long long k; cin >> k;
        long long ans = 0;
        vector<bool> bad(n);
        for (int i = N; i >= 0; i--) {
            long long mask = 1LL << i;
            __int128_t cost = 0;
            vector<bool> tmp = bad;
            for (int j = 0; j < n; j++) {
                if (tmp[j]) cost += mask;
                else {
                    if (a[j] & mask) continue;
                    tmp[j] = true;
                    cost += mask - (a[j] & (mask - 1));
                }
            }
            if (cost <= k) {
                ans |= mask;
                k -= cost;
                bad = tmp;
            }
        }
        cout << ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
