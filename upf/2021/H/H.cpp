#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();
    int l = n / 2 - 1, r = n / 2;
    while (abs(s[l] - s[r]) < 4) {
        l--; r++;
        if (l == -1 && r == n) {
            cout << "disparition" << endl;
            return 0;
        }
    }
    cout << s.substr(0, l + 1) << s.substr(r, n - r) << endl;
}