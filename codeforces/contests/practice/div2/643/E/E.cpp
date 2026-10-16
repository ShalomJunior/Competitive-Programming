#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, A, R, M;
    cin >> n >> A >> R >> M;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    sort(h.begin(), h.end());
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + h[i];
    M = min(M, A + R);
    auto get = [&](int H) {
        int j = upper_bound(h.begin(), h.end(), H) - h.begin();
        int l = H * (j - 1) - pref[j - 1];
        int r = (pref[n] - pref[j - 1]) - H * (n + 1 - j);
        int cost = min(l, r) * M + (l < r ? (r - l) * R : (l - r) * A);
        return cost;
        };
    int lo = h[1], hi = h.back();
    while (lo + 2 < hi) {
        int len = (hi - lo + 1);
        int l = lo + len / 3;
        int r = hi - len / 3;
        int cl = get(l);
        int cr = get(r);
        cl <= cr ? hi = r : lo = l;
    }
    int ans = INF;
    for (int i = lo; i <= hi; ++i) ans = min(ans, get(i));
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}