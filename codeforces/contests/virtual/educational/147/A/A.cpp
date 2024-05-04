#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    if (s[0] == '0') {
        cout << 0 << endl;
        return;
    }
    int n = (int)s.size();
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            if (i == 0) ans *= 9;
            else ans *= 10;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}