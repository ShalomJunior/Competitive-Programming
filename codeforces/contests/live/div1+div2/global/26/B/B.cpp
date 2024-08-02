#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    if (s[0] != '1' || s[n - 1] == '9') {
        cout << "NO" << endl;
        return;
    }
    int cnt = count(s.begin(), s.end() - 1, '0');
    cout << (cnt ? "NO" : "YES") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}