#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int tot = accumulate(a.begin(), a.end(), 0LL);
    double mean = (double)tot / n;
    if (ceil(mean * 2) != mean * 2) {
        cout << 0 << endl;
        return;
    }
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int sum = ceil(mean * 2);
        ans += mp[sum - a[i]];
        mp[a[i]]++;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
