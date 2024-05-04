#include <bits/stdc++.h>

using namespace std;


const string match = "YesYesYes";

void solve() {
    string s; cin >> s;
    int n = s.size();

    if (n < 3 && match.find(s) == -1 || match.find(s.substr(0, 3)) == -1) {
        cout << "NO" << endl;
        return;
    }

    for (int i = 3; i < n; i++) {
        if (s[i] != s[i - 3]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}