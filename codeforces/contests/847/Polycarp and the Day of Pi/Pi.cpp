#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    string comp = "314159265358979323846264338327";

    int out = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != comp[i])break;
        out++;
    }
    cout << out << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}