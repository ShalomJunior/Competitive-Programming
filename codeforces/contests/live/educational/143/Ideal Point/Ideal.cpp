#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    int mn = INT_MAX, mx = INT_MIN;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if (a <= k && k <= b) {
            v.push_back(pair<int, int>(a, b));
            mn = min(mn, a);
            mx = max(mx, b);
        }
    }

    if (v.size() == 0) {
        cout << "NO" << endl;
        return;
    }

    for (int i = mn; i <= mx; i++) {
        if (i == k) continue;
        int cnt = 0;
        for (auto& p : v)
            if (p.first <= i && i <= p.second)cnt++;

        if (cnt >= v.size()) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}