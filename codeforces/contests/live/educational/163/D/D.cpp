#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.length();
    int ans = 0;
    for (int len = 1; len <= n / 2; len++) {
        int seg = 0;
        for (int i = 0; i + len < n; i++) {
            if (s[i] == s[i + len] || s[i] == '?' || s[i + len] == '?')seg++;
            else {
                seg = 0;
            }
            if (seg == len) {
                ans = max(seg, seg);
                break;
            }
        }
    }
    cout << ans * 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
