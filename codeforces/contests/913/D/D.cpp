#include <bits/stdc++.h>
#define int long long
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

void solve() {
    int n; cin >> n;
    vector<Mine> a(n);
    for (auto& p : a)
        cin >> p.F >> p.S;
    int L = 0, R = 1e9;
    auto go = [&](int len) {
        Mine seg = { 0, 0 };
        for (int i = 0; i < n; i++) {
            seg.F -= len;
            seg.S += len;
            if (seg.S < a[i].F || seg.F > a[i].S) {
                return false;
            }
            seg.F = max(seg.F, a[i].F);
            seg.S = min(seg.S, a[i].S);
        }
        return true;
        };
    while (L < R) {
        int mid = (L + R) / 2;
        go(mid) ? R = mid : L = mid + 1;
    }
    cout << L << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
