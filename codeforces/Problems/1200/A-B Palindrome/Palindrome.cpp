#include <bits/stdc++.h>

using namespace std;

int a, b;
string s;

bool done(int idx) {
    int n = s.size();

    if (s[idx] == '0' && a > 0)
        s[n - 1 - idx] = '0', a--;
    else if (s[idx] == '1' && b > 0)
        s[n - 1 - idx] = '1', b--;
    else return false;

    return true;
}

void solve() {
    cin >> a >> b >> s;
    int n = a + b;

    for (auto& c : s) {
        if (c == '0')a--;
        else if (c == '1') b--;
    }

    if (a < 0 || b < 0) { cout << "-1\n"; return; }

    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && s[n - 1 - i] == '1' || s[i] == '1' && s[n - 1 - i] == '0') {
            cout << "-1\n";
            return;
        }
        if (s[i] != '?' && s[n - 1 - i] == '?') {
            if (!done(i)) { cout << "-1\n"; return; }
        }
    }

    for (int i = 0; i < n / 2; i++) {
        if (s[i] == '?') {
            if (a > 1)
                s[i] = s[n - 1 - i] = '0', a -= 2;
            else if (b > 1)
                s[i] = s[n - 1 - i] = '1', b -= 2;
            else {
                cout << "-1\n"; return;
            }
        }
    }

    if (s[n / 2] == '?') {
        if (a > 0)
            s[n / 2] = '0', a--;
        else if (b > 0) s[n / 2] = '1', b--;
        else { cout << "-1\n"; return; }
    }

    cout << s << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}