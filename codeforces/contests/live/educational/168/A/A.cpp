#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    cerr << s << endl;
    int n = s.length();
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == s[i + 1]) {
            cout << s.substr(0, i + 1) << (s[i] == 'a' ? 'b' : 'a') << s.substr(i + 1, n - (i + 1)) << endl;
            return;
        }
    }
    cout << (s[0] == 'a' ? 'b' : 'a') << s << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
