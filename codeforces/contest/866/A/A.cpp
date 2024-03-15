#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.length();
    if (n == 1) {
        cout << ((s[0] == '^') ? 1 : 2) << endl;
        return;
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1] && s[i] == '_') {
            ans++;
        }
    }
    if (s[0] == '_')ans++;
    if (s[n - 1] == '_')ans++;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}