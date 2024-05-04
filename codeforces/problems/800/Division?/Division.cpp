#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int r; cin >> r;
        string s = "Division ";
        if (r <= 1399) s += "4";
        else if (r <= 1599) s += "3";
        else if (r <= 1899) s += "2";
        else s += "1";

        cout << s << endl;
    }
}