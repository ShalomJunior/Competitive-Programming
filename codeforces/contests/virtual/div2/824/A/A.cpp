#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve() {
    int n; cin >> n;
    auto check = [&](int mid) {
        int x = 2;
        int y = x + mid + 2;
        return y <= n && n - y - 1 - (mid + 1) >= mid;
        };
    int L = 0, R = 1e9;
    while (L < R) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            if (L == mid) check(R) ? L = R : R = L;
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