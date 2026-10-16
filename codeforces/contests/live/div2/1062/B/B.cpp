#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int cnt = count(s.begin(), s.end(), 'B');
    while (q--) {
        int a;
        cin >> a;
        if (cnt == 0) {
            cout << a << endl;
            continue;
        }
        int i = 0;
        int ans = 0;
        while (a) {
            a = (s[i] == 'A' ? a - 1 : a / 2);
            ans++;
            i = (i + 1) % n;
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
