#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int d, s;
    cin >> d >> s;
    int ans = 0;
    auto go = [&](int n, int z) {
        int u = z - n * d;
        if (u % 2 == 0 && n > 1) {
            ans++;
        }
        };
    int S = s * 2;
    for (int k = 1; k * k <= S; k++) {
        if (S % k == 0) {
            go(k - 1, S / k);
            if (k * k < s) go(S / k - 1, k);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}