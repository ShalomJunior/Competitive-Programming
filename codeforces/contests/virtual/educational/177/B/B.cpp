#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    reverse(a.begin(), a.end());
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }
    int s = pref[n];
    int r = x % s;
    int j = 0;
    while (pref[j] < r) j++;
    int mn = j + (x / s) * n;
    if (mn > k * n) {
        cout << 0;
    }
    else {
        cout << k * n - mn + 1;
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
