#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = 0, sum = 0;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        if (a[i] <= 0) continue;
        if (ms.size() < m) {
            ms.insert(a[i]);
            sum += a[i];
        }
        else if (*ms.begin() < a[i]) {
            sum += (a[i] - *ms.begin());
            ms.erase(ms.begin());
            ms.insert(a[i]);
        }
        ans = max(ans, sum - (i + 1) * d);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}