#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string a, b;
    cin >> n >> a >> b;
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        char ai = a[i], aj = a[n - 1 - i];
        char bi = b[i], bj = b[n - 1 - i];
        map<char, int> h;
        h[ai]++, h[aj]++, h[bi]++, h[bj]++;
        int m = h.size();
        int M = 0;
        for (auto& [c, cnt] : h) M = max(M, cnt);
        if (m == 1)continue;
        if (m == 2) ans += (M == 2 ? 0 : 1);
        if (m == 3) {
            if (ai == aj) ans += 2;
            else ans++;
        }
        if (m == 4) ans += 2;
    }
    if ((n & 1) && a[n / 2] != b[n / 2]) ans++;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}