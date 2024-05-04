#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<bool> b(n);
    b[0] = s[0] == '1';
    for (int i = 1; i < n; i++) {
        if (s[i] == '1') {
            b[i - 1] = b[i] = true;
        }
    }
    int ans = 0;
    int i = 0;
    while (i < n) {
        if (b[i]) {
            int tot = a[i];
            int mn = a[i];
            int cnt = 1;
            bool flag = s[i] == '0';
            int j = i + 1;
            while (j < n && s[j] != '0') {
                tot += a[j];
                mn = min(mn, a[j]);
                flag |= s[j] == '0';
                cnt++;
                j++;
            }
            ans += tot - (flag ? mn : 0);
            i = j;
        }
        else i++;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
