#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    bool f = false;
    int idx = 0;
    char c = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] <= c) {
            c = s[i]; idx = i;
            f = true;
        }
    }
    if (!f) { cout << s << endl;return; }

    s.erase(s.begin() + idx);
    s = c + s;
    cout << s << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}