#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    map<int, vector<int>> h;
    h[a[0]].push_back(0);
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            h[a[i]].push_back(i);
        }
    }
    if (set<int>(a.begin(), a.end()).size() == 1) {
        cout << 0 << endl;
        return;
    }
    int ans = 1e9;
    for (auto& [k, v] : h) {
        int cnt = v.size() - 1;
        if (v[0] != 0) cnt++;
        if (v.back() != n - 1 && a.back() != k) cnt++;
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}