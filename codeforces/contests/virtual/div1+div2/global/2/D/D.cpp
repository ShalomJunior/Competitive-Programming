#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 5e18;
void solve() {
    int n;
    cin >> n;
    vector<int> s(n);
    for (auto& c : s) cin >> c;
    sort(s.begin(), s.end());
    multiset<int> ms;
    for (int i = 0; i + 1 < n; i++) {
        ms.insert(s[i + 1] - s[i]);
    }
    ms.insert(INF - s.back());
    int q;
    cin >> q;
    vector<pair<int, int>> qs(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        qs[i] = { l, r };
    }
    vector<int> o(q);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](const int& i, const int& j) {
        return qs[i].second - qs[i].first < qs[j].second - qs[j].first;
        });
    vector<int> ans(q);
    int tot = 0;
    for (int i = 0; i < q; i++) {
        int len = qs[o[i]].second - qs[o[i]].first + 1;
        while (!ms.empty() && *ms.begin() <= len) {
            tot += *ms.begin();
            ms.erase(ms.begin());
        }
        ans[o[i]] = tot + ms.size() * len;
    }
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}