#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int tp = 0;
    string match = "";
    for (int i = 0; i < n; i++) {
        match.push_back(s[i]);
        if (tp & 1) {
            match.push_back(s[i]), i++;
        }
        tp++;
    }

    cout << ((s == match) ? "YES\n" : "NO\n");
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}