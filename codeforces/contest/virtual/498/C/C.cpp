#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a)cin >> c;
    map<int, int> pref, suff;
    for (int i = 0, sum = 0; i < n; i++) {
        sum += a[i];
        pref[sum] = i + 1;
    }
    for (int i = 0, sum = 0; i < n; i++) {
        sum += a[n - 1 - i];
        suff[sum] = i + 1;
    }
    int ans = 0;
    for (auto& [sum, a] : pref) {
        if (suff.count(sum)) {
            int used = a + suff[sum];
            if (used <= n) ans = sum;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}