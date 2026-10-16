#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (auto& c : a) {
        cin >> c;
        mp[c]++;
    }
    auto f = [&](int _v) {
        int cnt = 0;
        for (auto& [k, v] : mp) {
            if (v == _v) cnt++;
        }
        return cnt;
        };
    int x = f(1);
    int y = set<int>(a.begin(), a.end()).size() - x;
    int ans = ((x + 1) / 2) * 2 + y;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
