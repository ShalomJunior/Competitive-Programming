#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    long long ans = n;
    for (int i = 0; i + 1 < n; i++) {
        string p = s.substr(i, 2);
        if (p == "01" || p == "10") ans += i + 1;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}