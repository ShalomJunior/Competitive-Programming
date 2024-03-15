#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int ans = 1e9, curr = 0;;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W')curr++;
        if (i >= k && s[i - k] == 'W') curr--;
        if (i >= k - 1) ans = min(ans, curr);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}