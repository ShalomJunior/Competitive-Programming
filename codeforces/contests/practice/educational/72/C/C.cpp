#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 18;
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> pref(n);
    for (int i = 1; i < n; i++) {
        pref[i] = (s[i - 1] == '0' ? pref[i - 1] + 1 : 0);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;
        int x = 0;
        for (int j = 0; j <= N && i + j < n; j++) {
            x *= 2;
            x += (s[i + j] - '0');
            if (pref[i] >= x - (j + 1)) ans++;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
