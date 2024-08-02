#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int r;
    cin >> r;
    int ans = 0;
    for (int x = -r; x <= r; x++) {
        auto left = r * r - x * x;
        auto right = (r + 1) * (r + 1) - x * x;
        left = ceil(sqrt(left));
        right = sqrtl(right);
        int a = ceil(left);
        int b = floor(right - 0.1);
        cerr << a << " " << b << endl;
        int cnt = (b - a + 1) * 2;
        if (a == 0) cnt--;
        ans += cnt;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}