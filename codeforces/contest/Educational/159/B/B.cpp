#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, p, l, t;
    cin >> n >> p >> l >> t;
    int best = 1 + (n - 1) / 7;
    auto go = [&](int rest) {
        int work = n - rest;
        int cnt = min(work, best / 2);
        int have = 1LL * cnt * (l + t * 2);
        work -= cnt;
        if (work && best & 1) {
            have += l + t;
            work--;
        }
        have += work * l;
        return have >= p;
        };
    int L = 0, R = n;
    while (L < R) {
        int mid = (L + R) / 2;
        if (go(mid)) {
            if (L == mid) go(R) ? L = R : R = L;
            else L = mid;
        }
        else R = mid - 1;
    }
    cout << L << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
