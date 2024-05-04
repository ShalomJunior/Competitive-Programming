#include <bits/stdc++.h>

using namespace std;

void solve() {
    cout << "TESTCASE" << endl;
    int n; cin >> n;
    vector<int> v(n);
    for (auto& c : v)
        cin >> c;

    unordered_map<int, int>h;
    for (auto& c : v)
        h[c]++;

    set<int> s(v.begin(), v.end());

    int ans = 0;
    int sz = 0;
    for (auto it = s.begin(); it != prev(s.end());++it) {
        int curr = *it;
        int nxt = *next(it);
        sz += h[curr];
        cout << sz << "->" << endl;
        if (sz - 1 >= curr && sz - 1 + h[nxt] < nxt) {
            ans++;
        }
    }

    cout << ans + 1 << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}