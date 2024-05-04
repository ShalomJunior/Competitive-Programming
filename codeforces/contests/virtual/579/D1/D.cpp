#include <bits/stdc++.h>
using namespace std;

bool is(string s, string t) {
    int n = s.length(), m = t.length();
    if (n < m) return false;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[j]) j++;
        if (j == m) break;
    }
    return j == m;
}

void solve() {
    string s, t; cin >> s >> t;
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            string a = s.substr(0, i) + s.substr(i + j, n - (i + j));
            if (is(a, t)) {
                ans = max(ans, j);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}