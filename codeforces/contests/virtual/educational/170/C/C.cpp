#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        h[a]++;
    }
    int ans = 0;
    vector<pair<int, int>> v;
    for (auto& [id, cnt] : h) v.push_back({ id, cnt });
    int m = v.size();
    for (int i = 0; i < m; i++) {
        int j = i;
        vector<int> pref = { 0 , v[j].second };
        while (j + 1 < m && v[j + 1].first == v[j].first + 1) {
            j++;
            pref.push_back(pref.back() + v[j].second);
        }
        for (int l = 1; l < pref.size(); ++l) {
            ans = max(ans, pref[l] - (l - k >= 0 ? pref[l - k] : 0));
        }
        i = j;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
