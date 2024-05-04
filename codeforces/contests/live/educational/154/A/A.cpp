#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int i = 0, j = 0;
    for (int k = 0; k < 9; k++) {
        if (s[k] == '1') i = k;
        else if (s[k] == '7') j = k;
    }
    cout << (i < j ? 17 : 71) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
