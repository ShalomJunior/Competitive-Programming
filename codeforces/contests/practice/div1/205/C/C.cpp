#include<bits/stdc++.h>
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
    string s;
    cin >> s;
    s = "#" + s;
    int tot = 0;
    int suff = 0;
    for (int i = n; i > 0; i--) {
        if (s[i] == '1') {
            tot = max(tot, pref[i - 1] + suff);
        }
        suff += (s[i] == '1' ? a[i] : 0);
    }
    cout << max(tot, suff) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}