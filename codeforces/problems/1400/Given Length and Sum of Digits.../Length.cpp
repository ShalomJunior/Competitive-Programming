#include <bits/stdc++.h>

using namespace std;

string mn(int m, int s) {
    string str;
    if (9 * m == s)
        return string(m, '9');

    while (s > 9) {
        str = "9" + str; s -= 9; m--;
    }

    if (m == 1) {
        str = to_string(s) + str;
        return str;
    }
    else {
        if (s == 1) {
            str = string(m - 1, '0') + str;
            m = 1;
        }
        else {
            str = to_string(s - 1) + str; m--;

            str = string(m - 1, '0') + str;
            m = 1;
        }
    }

    str = "1" + str;

    return str;
}

string mx(int m, int s) {
    string str;

    if (9 * m == s)
        return string(m, '9');

    str += string(s / 9, '9');
    m -= s / 9; s %= 9;

    str += to_string(s); m--;

    str += string(m, '0');

    return str;
}

int main() {
    int m, s; cin >> m >> s;

    if (9 * m < s || s == 0 && m > 1)
        cout << "-1 -1" << endl;
    else
        cout << mn(m, s) << " " << mx(m, s) << endl;
}