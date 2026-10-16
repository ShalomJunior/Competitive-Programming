#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> from;
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
        r[i]--;
        from[r[i]]++;
    }
    set<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        p.insert({ from[i], i });
    }
    int ans = 1;
    while (true) {
        vector<int> id;
        while (p.begin()->first == 0) {
            id.push_back(r[p.begin()->second]);
            p.erase(p.begin());
        }
        if (id.empty()) break;
        ans++;
        for (auto& c : id) {
            p.erase({ from[c], c });
            from[c]--;
            p.insert({ from[c], c });
        }
    }
    cout << ans + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}