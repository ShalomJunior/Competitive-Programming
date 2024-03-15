#include <bits/stdc++.h>

using namespace std;

int rec(string s) {
    int cn = 0;
    for (int i = 1; i < s.length(); i++) {
        if (s[i - 1] == s[i] || s[i + 1] == s[i]) {
            s = s.substr(0, i) + s.substr(i + 1, s.length());
            cn += rec(s);
            cn++;
            break;
        }
    }
    return cn;
}

int main() {
    int n; cin >> n;
    string s; cin >> s;

    cout << rec(s) << endl;
}