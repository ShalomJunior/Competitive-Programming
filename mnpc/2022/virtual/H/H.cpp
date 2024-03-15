#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.length();
    string t = s;
    int mx = 0, id = 0, k = 0;
    while (k++ < 700) {
        t.pop_back();
        int m = t.length();
        if (m == 0) break;
        int matches = 0;
        for (int i = 0; i < m; i++) {
            matches += (t[m - 1 - i] == s[n - 1 - i]);
        }
        if (matches > mx) {
            mx = matches;
            id = n - m;
        }
    }
    cout << mx << " " << id << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
