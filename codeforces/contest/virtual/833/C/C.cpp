#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), pref(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i] = a[i] + (i ? pref[i - 1] : 0);
    }
    int ans = 0;
    for (int f = 1, i = 0; i < n; i++) {
        if (!a[i]) {
            map<int, int> cnt;
            cnt[pref[i]]++;
            int j = i + 1, mx = 1;
            while (j < n && a[j]) {
                cnt[pref[j]]++;
                mx = max(mx, cnt[pref[j]]);
                j++;
            }
            i = j - 1;
            ans += mx;
            f = 0;
        }
        else { if (f && !pref[i]) ans++; }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}