#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int i = 0, n = s.size(), ans = 0;
    while (i < n && s[i] != '0') i++;
    if (i == n) i = n - 1;
    while (i >= 0 && s[i] != '1') { ans++, i--; }
    if (i >= 0) ans++;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}