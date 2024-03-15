#include <bits/stdc++.h>

using namespace std;

void del(string& s, char patt) {
    while (s[0] == patt) {
        s.erase(s.begin());
    }
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    for (auto& c : s)
        c = tolower(c);

    bool all = (s.find('m') != string::npos);
    all &= (s.find('e') != string::npos);
    all &= (s.find('o') != string::npos);
    all &= (s.find('w') != string::npos);

    if (!all) {
        cout << "NO" << endl;
        return;
    }

    del(s, 'm'); del(s, 'e');
    del(s, 'o'); del(s, 'w');

    if (s.size() > 0) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}