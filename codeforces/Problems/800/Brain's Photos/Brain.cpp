#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, c; cin >> r >> c;
    char ch;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            cin >> ch;
            if (ch != 'B' && ch != 'W' && ch != 'G') { cout << "#Color" << endl; return 0; }
        }

    cout << "#Black&White" << endl;

}