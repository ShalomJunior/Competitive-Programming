#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a;
    cin >> n >> a;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    set<int> p(c.begin(), c.end());
    set<pair<int, int>> s;
    for (auto& c : p) s.insert({ 0, c });
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int val = cnt[c[i]];
        if (p.count(c[i]) && c[i] != a) {
            s.erase({ val, c[i] });
            s.insert({ val + 1, c[i] });
        }
        cnt[c[i]]++;
        while (!s.empty() && s.begin()->first < cnt[a]) {
            p.erase(s.begin()->second);
            s.erase(s.begin());
        }
    }
    cout << (s.empty() ? -1 : s.begin()->second) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}