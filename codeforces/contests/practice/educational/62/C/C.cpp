#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (auto& [b, t] : a) cin >> t >> b;
    sort(a.begin(), a.end());
    multiset<int> lead;
    multiset<int> all;
    for (auto& [b, t] : a) all.insert(t);
    int ans = 0;
    int tot = 0;
    for (auto& [b, t] : a) {
        while (lead.size() < k && !all.empty()) {
            auto it = prev(all.end());
            lead.insert(*it);
            tot += *it;
            all.erase(it);
        }
        if (lead.count(t)) {
            ans = max(ans, b * tot);
            lead.erase(lead.find(t));
            tot -= t;
        }
        else {
            ans = max(ans, b * (tot + t - *lead.begin()));
            all.erase(all.find(t));
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
