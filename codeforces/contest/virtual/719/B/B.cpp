#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int len = s.length();
    int ans = 9 * (len - 1) + (s[0] - '0') - 1;
    string t(len, s[0]);
    if (t <= s) ans++;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}