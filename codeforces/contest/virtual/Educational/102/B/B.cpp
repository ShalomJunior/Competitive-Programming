#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b; cin >> a >> b;
    int n = a.length(), m = b.length();
    int len = lcm(n, m);
    string sa, sb;
    while (sa.length() < len) sa += a;
    while (sb.length() < len) sb += b;
    cout << (sa.substr(0, len) == sb.substr(0, len) ? sa.substr(0, len) : "-1") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}