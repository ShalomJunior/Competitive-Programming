#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        if (s[i] == t[j] || s[i] == '?') {
            s[i] = t[j];
            i++;
            j++;
        }
        else {
            i++;
        }
    }
    if (j == m) {
        cout << "YES" << endl;
        for (auto& c : s) {
            cout << (c == '?' ? 'a' : c);
        }
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}