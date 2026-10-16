#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int i = 0;
    while (i < n) {
        int j = 0;
        while (i + j < n && s[i + j] == s[i]) j++;
        if (j == 1) {
            cout << "NO" << endl;
            return;
        }
        i += j;
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
