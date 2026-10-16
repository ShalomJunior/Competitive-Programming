#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i + 2 < n && i < 1; i++) {
        if (s[i] == '1' && s[i + 1] == '0' && s[i + 2] != '0') {
            int x = stoi(s.substr(i + 2, n - (i + 2)));
            if (x >= 2) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
