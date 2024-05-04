#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; char c;
    cin >> s >> c;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == c && i % 2 == 0) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}