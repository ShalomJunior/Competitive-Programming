#include <bits/stdc++.h>

using namespace std;

string pattern;

void solve() {
    int k; cin >> k;
    string s; cin >> s;

    for (int i = 0; i < 8; i++) {
        if (pattern.substr(i, k) == s) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {

    for (int i = 1; i < 40; i++) {
        if (i % 15 == 0)pattern += "FB";
        else if (i % 3 == 0) pattern += "F";
        else if (i % 5 == 0) pattern += "B";
    }
    int t; cin >> t;
    while (t--)solve();
}