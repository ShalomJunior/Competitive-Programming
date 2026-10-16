#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;
const int N = 1000;
void solve() {
    int n, x;
    string s;
    cin >> n >> x >> s;
    vector<int> pref(n);
    int mn = INF;
    int mx = 0;
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        pref[i] = (i ? pref[i - 1] : 0) + (s[i] == '0' ? 1 : -1);
        h[pref[i]]++;
        mn = min(mn, pref[i]);
        mx = max(mx, pref[i]);
    }
    int m = pref[n - 1];
    if (m == 0) {
        if ((mn <= x && x <= mx) || x == 0) {
            cout << -1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
    else {
        int ans = (x == 0);
        int last = (x / m) * m;
        if (x > 0 && m > 0) {
            while (last && last - m + mx >= x) last -= m;
        }
        else if (x < 0 && m < 0) {
            while (last && last - m + mn <= x) last -= m;
        }
        else {
            last = 0;
        }
        for (int i = 0; i < n + N; i++) {
            ans += h[x - last];
            last += m;
        }
        cout << ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
