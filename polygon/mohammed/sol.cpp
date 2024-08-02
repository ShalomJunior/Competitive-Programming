#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    set<int> p(a.begin(), a.end());
    set<pair<int, int>> s;
    for (auto& c : p) s.insert({ 0, c });
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int val = cnt[a[i]];
        if (p.count(a[i]) && a[i] != m) {
            s.erase({ val, a[i] });
            s.insert({ val + 1, a[i] });
        }
        cnt[a[i]]++;
        while (!s.empty() && s.begin()->first < cnt[m]) {
            p.erase(s.begin()->second);
            s.erase(s.begin());
        }
    }
    cout << (s.empty() ? -1 : s.begin()->second) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}