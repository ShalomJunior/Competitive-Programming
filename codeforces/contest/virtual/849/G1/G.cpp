#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, c; cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] += i + 1;
    }
    sort(a.begin(), a.end());
    vector<int> pref(n);
    for (int i = 0; i < n; i++) {
        pref[i] = a[i] + (i ? pref[i - 1] : 0);
    }
    auto it = upper_bound(pref.begin(), pref.end(), c);
    cout << (it == pref.begin() ? 0 : it - pref.begin()) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}