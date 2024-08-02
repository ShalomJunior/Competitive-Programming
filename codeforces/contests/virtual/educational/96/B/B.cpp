#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    int ans = accumulate(a.begin() + n - k - 1, a.end(), 0LL);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
