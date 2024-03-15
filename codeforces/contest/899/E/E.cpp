#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    auto go = [&](int mid) {
        int use = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < mid) use += mid - a[i];
        }
        return use <= x;
        };
    int L = 1, R = 2e9;
    while (L < R) {
        int mid = (L + R) / 2;
        if (go(mid)) {
            if (L == mid) go(mid + 1) ? L = mid + 1 : R = mid;
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
    while (t--)solve();
}
