#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    auto b = a;
    reverse(b.begin(), b.end());
    set<int> pos;
    set<int> neg;
    for (int i = 0; i + 1 < n; i++) {
        int d = a[i + 1] - a[i];
        if (d <= 0) neg.insert(d);
        if (d >= 0) pos.insert(d);
    }
    if (pos.size() > 1 || neg.size() > 1) {
        cout << -1 << endl;
        return;
    }
    if (is_sorted(a.begin(), a.end()) || is_sorted(b.begin(), b.end())) {
        cout << 0 << endl;
        return;
    }
    int c = *pos.begin();
    int z = *neg.begin();
    int M = c - z;
    for (int i = 1; i < n; i++) {
        if (a[i] != (a[i - 1] + c) % M) {
            cout << -1 << endl;
            return;
        }
    }
    if (*max_element(a.begin(), a.end()) < M) {
        cout << M << " " << c << endl;
    }
    else {
        cout << -1 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}