#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = 0;
    int s = 0;
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++) {
        s += a[i] - (i + 1);
        ans = max(ans, s);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}