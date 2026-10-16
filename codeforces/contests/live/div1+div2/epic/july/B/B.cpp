#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> need;
    for (int i = 0, mx = 0; i < n; i++) {
        if (a[i] < mx) need.push_back(mx - a[i]);
        else if (a[i] > mx)  mx = a[i];
        else {}
    }
    sort(need.begin(), need.end());
    int m = need.size();
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int r = m - i;
        ans += (need[i] - cnt) * (r + 1);
        cnt = need[i];
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
