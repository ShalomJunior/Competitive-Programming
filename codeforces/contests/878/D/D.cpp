#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a)cin >> c;
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    int L = 0, R = a[n - 1];
    while (L < R) {
        int mid = (L + R) / 2;
        int lo = a[0] + 2 * mid, hi = a[n - 1] - 2 * mid;
        auto f = upper_bound(a.begin(), a.end(), lo);
        auto s = lower_bound(a.begin(), a.end(), hi);
        f == a.end() || s == a.begin() || *--s - *f + 1 <= 2 * mid + 1 ? R = mid : L = mid + 1;
    }
    cout << L << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}