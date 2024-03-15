#include <bits/stdc++.h>

using namespace std;

int main() {
    char c; string s;
    while (cin >> c)
        if (c != '+') s += c;

    cin >> s;
    sort(s.begin(), s.end());

    for (int i = 0; i < s.size() - 1;i++)
        cout << s[i] << "+";

    cout << s[s.size() - 1] << endl;

}