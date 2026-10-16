#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    if (pref[n] % 3) {
        cout << 0 << endl;
        return;
    }
    int sum = pref[n] / 3;
    vector<int> idx;
    for (int i = 1; i < n; i++) {
        if (pref[i] == sum) {
            idx.push_back(i);
        }
    }
    int ans = 0;
    for (int j = n; j >= 3; j--) {
        while (!idx.empty() && idx.back() >= j - 1) {
            idx.pop_back();
        }
        int s = pref[n] - pref[j - 1];
        if (s == sum) {
            ans += idx.size();
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
