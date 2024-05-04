#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.length();
    int a = count(s.begin(), s.end(), '0');
    int b = count(s.begin(), s.end(), '1');
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (b) b--;
            else {
                cout << n - i << endl;
                return;
            }
        }
        else {
            if (a) a--;
            else {
                cout << n - i << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
