#include <bits/stdc++.h>

using namespace std;

void solve() {
    string a, b; cin >> a >> b;

    int len1 = a.length();
    int len2 = b.length();
    bool fn = false;
    string patt;
    for (int i = 0; i < len1 - 1; i++) {
        string sub = a.substr(i, 2);
        if (b.find(sub) != string::npos) {
            fn = true;
            patt = sub;
            break;
        }
    }

    if (fn) {
        cout << "YES" << endl;
        cout << "*" << patt << "*" << endl;
        return;
    }

    if (a[0] == b[0]) {
        cout << "YES" << endl;
        cout << a[0] << "*" << endl;
    }
    else if (a[len1 - 1] == b[len2 - 1]) {
        cout << "YES" << endl;
        cout << "*" << a[len1 - 1] << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}