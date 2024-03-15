#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> x(n), y(n);
    map<int, int> cnt;
    cnt[0]++;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            y[i] = a[i] + y[i - 1];
            x[i] = x[i - 1];
        }
        else {
            x[i] = a[i] + (i ? x[i - 1] : 0);
            y[i] = (i ? y[i - 1] : 0);
        }
        cnt[x[i] - y[i]]++;
    }
    for (auto& [k, v] : cnt) {
        if (v > 1) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}