#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.length();
    for (int i = 1; i < n; i++) {
        string a = s.substr(0, i);
        string b = s.substr(i, n - i);
        if ((a[0] == '0' && i > 1) || (b[0] == '0' && n - i > 1)) continue;
        int x = stoi(a), y = stoi(b);
        if (x < y) {
            cout << x << " " << y << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
