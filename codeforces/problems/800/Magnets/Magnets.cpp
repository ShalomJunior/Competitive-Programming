#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    string s;
    while (n--) {
        string x; cin >> x;
        s += x;
    }

    int inver = 1;
    for (int i = 1; i < s.size(); i++)
        (s[i] == s[i - 1]) ? inver++ : inver;

    cout << inver << endl;
}