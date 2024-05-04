#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int i = 0;
    int j = n - 1;
    while (k > 1 && i < j) {
        int r = k / 2;
        int t = min({ r, a[i], a[j] });
        k -= t * 2;
        a[i] -= t;
        a[j] -= t;
        if (a[i] == 0) i++;
        if (a[j] == 0) j--;
    }
    if (k && i < n) {
        int t = min(k, a[i]);
        a[i] -= t;
        k -= t;
    }
    int ans = count(a.begin(), a.end(), 0);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
