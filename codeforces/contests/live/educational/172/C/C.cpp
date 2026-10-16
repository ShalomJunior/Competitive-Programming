#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    s = "#" + s;
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + (s[i] == '1' ? 1 : -1);
    }
    for (int i = 1; i <= n; i++) {

    }
    int cnt = 0;
    int z = 0;
    int ans = n + 1;
    for (int i = n; i > 1; i--) {
        if (s[i] == '1') cnt++;
        else if (s[i] == '0') cnt--;
        else {}
        if (cnt > 0) {
            z++;
            if (z * (z + 1) / 2 >= k) {
                cout << z + 1 << endl;
                return;
            }
            cnt = 0;
        }

    }
    cout << -1 << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
