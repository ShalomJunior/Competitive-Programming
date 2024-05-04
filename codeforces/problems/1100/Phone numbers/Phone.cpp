#include <bits/stdc++.h>

using namespace std;

void pf(int idx, string s) {
    for (int i = idx; i < s.length(); i += 2) {
        cout << s[i] << s[i + 1];
        (i == s.length() - 2) ? cout << "" : cout << "-";
    }
}

int main() {
    int n; cin >> n;
    string s; cin >> s;
    if (n < 4)
        cout << s << endl;
    else if (n % 2 == 0)
        pf(0, s);
    else {
        cout << s.substr(0, 3) << "-";
        pf(3, s);
    }
    cout << endl;

}