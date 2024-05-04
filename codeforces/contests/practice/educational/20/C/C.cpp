#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (__int128_t(k) * (k + 1) / 2 > n) {
        cout << -1 << endl;
        return;
    }
    int g = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i) continue;
        int g1 = i;
        auto x = __int128_t(k) * (g1 + k * g1) / 2;
        if (x <= n) g = max(g, g1);
        int g2 = n / i;
        auto y = __int128_t(k) * (g2 + k * g2) / 2;
        if (y <= n) g = max(g, g2);
    }
    int curr = 0;
    for (int i = 0; i < k - 1; i++) {
        cout << g * (i + 1) << " ";
        curr += g * (i + 1);
    }
    cout << n - curr << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}