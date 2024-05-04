#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s = to_string(n);
    int cost = 1000, ans = n;
    for (int i = 0; i < 1000; i++) {
        int m = 7 * i;
        string t = to_string(m);
        if (t.length() != s.length()) continue;
        int curr = 0;
        for (int j = 0; j < t.length(); j++) {
            if (s[j] != t[j]) curr++;
        }
        if (curr < cost) {
            ans = m;
            cost = curr;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}