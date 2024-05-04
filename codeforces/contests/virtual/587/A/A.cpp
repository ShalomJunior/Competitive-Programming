#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s; cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n - 1; i += 2) {
        if (s[i] == s[i + 1]) {
            if (s[i] == 'a') s[i] = 'b';
            else s[i] = 'a';
            ans++;
        }
    }
    cout << ans << endl;
    cout << s << endl;
}

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}