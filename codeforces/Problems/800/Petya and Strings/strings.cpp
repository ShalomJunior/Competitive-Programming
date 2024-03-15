#include <bits/stdc++.h>

using namespace std;

string lower(string str) {
    for (auto& c : str)
        c = tolower(c);
    return str;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    s1 = lower(s1);
    s2 = lower(s2);

    if (s1 < s2) cout << -1 << endl;
    else if (s1 == s2) cout << 0 << endl;
    else cout << 1 << endl;
}