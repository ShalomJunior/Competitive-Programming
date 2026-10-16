#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int i = 0;
    int j = 0;
    set<char> let;
    while (i < n) {
        while (j < n && s[j] == s[i]) j++;
        if ((j - i) & 1) let.insert(s[i]);
        i = j;
    }
    for (auto& c : let) cout << c;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
