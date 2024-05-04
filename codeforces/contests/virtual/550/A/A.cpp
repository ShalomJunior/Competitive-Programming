#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    sort(s.begin(), s.end());
    for (int i = 1; i < s.length(); i++) {
        if (s[i] != s[0] + i) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}