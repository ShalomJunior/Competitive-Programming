#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int i = 0;
    string r;
    while (i < n) {
        int j = 0;
        while (i + j < n && s[i + j] == s[i]) j++;
        if (s[i] == 'N') {
            r += string(j, 'N');
        }
        else {
            r += s[i];
        }
        i += j;
    }
    int m = r.size();
    if (m == 1) {
        cout << "YES";
    }
    else if (m == 2) {
        cout << (r[0] == r[1] ? "YES" : "NO");
    }
    else {
        cout << (r == "ENE" || r == "NEE" ? "NO" : "YES");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
