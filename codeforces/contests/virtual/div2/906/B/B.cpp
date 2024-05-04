#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    bool f = false;
    bool g = false;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i]) {
            f |= s[i] == '0';
            g |= s[i] == '1';
        }
    }
    bool h = false;
    for (int i = 1; i < m; i++) {
        h |= t[i] == t[i - 1];
    }
    if (!f && !g) {
        cout << "YES";
    }
    else if (f && g) {
        cout << "NO";
    }
    else {
        if (f) {
            cout << (!h && t[0] == t.back() && t[0] == '1' ? "YES" : "NO");
        }
        if (g) {
            cout << (!h && t[0] == t.back() && t[0] == '0' ? "YES" : "NO");
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}