#include <bits/stdc++.h>
using namespace std;

const string match = "codeforces";
void solve() {
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != match[i]) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}