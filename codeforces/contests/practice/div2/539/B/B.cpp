#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    int tot = accumulate(a.begin(), a.end(), 0LL);
    long double best = 0;
    for (int i = 0; i <= m && i < n; i++) {
        tot -= a[i];
        int r = n - i;
        int sup = min(m - i, r * k);
        long double curr = (long double)(tot + sup) / (long double)(r);
        best = max(best, curr);
    }
    printf("%.20Lf\n", best);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
