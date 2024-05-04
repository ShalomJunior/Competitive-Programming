#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    set<char> chars(s.begin(), s.end());
    if (chars.size() & 1) cout << "IGNORE HIM!" << endl;
    else cout << "CHAT WITH HER!" << endl;
}