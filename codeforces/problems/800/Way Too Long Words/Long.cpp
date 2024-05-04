#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    int sz = s.size();
    if (sz <= 10)
        cout << s << endl;
    else
        cout << s[0] << sz - 2 << s[sz - 1] << endl;
}

int main() {
    int n; cin >> n;
    while (n--) solve();
}