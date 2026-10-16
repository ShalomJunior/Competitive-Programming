#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<int> a(w);
    for (auto& c : a) cin >> c;
    vector<int> cnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int di = min({ k, i + 1, n - i, n - k + 1 });
            int dj = min({ k, j + 1, m - j, m - k + 1 });
            di = max(di, 1LL);
            dj = max(dj, 1LL);
            cnt.push_back(di * dj);
        }
    }
    sort(cnt.rbegin(), cnt.rend());
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for (int i = 0; i < w; i++) ans += a[i] * cnt[i];
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
