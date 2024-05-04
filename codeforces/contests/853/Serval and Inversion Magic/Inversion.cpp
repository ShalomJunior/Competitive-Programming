#include <bits/stdc++.h>

using namespace std;

bool is(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i])
            return false;
    }
    return true;
}


void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (is(s)) {
        cout << "YES" << endl;
        return;
    }
    int l, r;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            l = i;
            break;
        }
    }

    r = l;
    for (int i = l + 1; i < n / 2; i++) {
        if (s[i] == s[n - 1 - i]) {
            break;
        }
        r++;
    }

    for (int i = l; i <= r; i++) {
        if (s[i] == '0') s[i] = '1';
        else s[i] = '0';
    }

    if (is(s))
        cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}