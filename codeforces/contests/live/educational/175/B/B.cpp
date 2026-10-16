#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, x, k;
    string s;
    cin >> n >> x >> k >> s;
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i] = (i ? pref[i - 1] : 0) + (s[i] == 'L' ? -1 : 1);
    }
    auto get = [&](int v) {
        int j = 0;
        while (j < n && pref[j] != v) j++;
        return j;
        };
    int j = get(-x);
    if (j == n || j + 1 > k) {
        cout << 0;
    }
    else {
        k -= j + 1;
        j = get(0);
        cout << 1 + (j == n ? 0 : k / ++j);
    }
    cout << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
