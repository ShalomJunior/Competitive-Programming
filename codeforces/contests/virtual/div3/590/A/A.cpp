#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int sum = accumulate(a.begin(), a.end(), 0);
    sort(a.begin(), a.end());
    auto go = [&](int mid) {
        return n * mid >= sum;
        };
    int L = 0, R = a[n - 1];
    while (L < R) {
        int mid = (L + R) / 2;
        bool b = go(mid);
        go(mid) ? R = mid : L = mid + 1;
    }
    cout << L << endl;
}

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}