#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e10;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> b(n);
    for (auto& c : b) cin >> c;
    sort(a.rbegin(), a.rend());
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cnt += b[i];
        if (cnt > n) break;
        ans = max(ans, a[cnt - 1] * (i + 1));
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}