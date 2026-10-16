#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    set<int> all;
    vector<pair<int, int>> a(n);
    for (auto& [l, r] : a) {
        cin >> l >> r;
        all.insert(l);
        all.insert(r);
    }
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](const int& i, const int& j) {
        if (a[i].first != a[j].first) return a[i].first < a[j].first;
        return a[i].second < a[j].second;
        });
    set<pair<int, int>> in;
    vector<int> ans(n, -1);
    int j = 0;
    int k = 1;
    set<int> ids;
    for (auto& c : all) {
        if (in.empty()) {
            k = (k == 1 ? 2 : 1);
        }
        while (j < n && a[o[j]].first <= c) {
            in.insert({ a[o[j]].second, o[j] });
            ans[o[j]] = k;
            j++;
        }
        while (!in.empty() && in.begin()->first == c) in.erase(in.begin());
    }
    for (auto& c : ans) {
        if (c == -1) {
            c = k;
            k = k == 1 ? 2 : 1;
        }
    }
    if (set<int>(ans.begin(), ans.end()).size() == 2) {
        for (auto& c : ans) cout << c << " ";
    }
    else {
        cout << -1;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
