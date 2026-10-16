#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    string r;
    r += s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] == '1') r += '1';
        else if (s[i] == '0' && r.back() != '0') r += '0';
    }
    int x = count(r.begin(), r.end(), '0');
    int y = count(r.begin(), r.end(), '1');
    cout << (y > x ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}