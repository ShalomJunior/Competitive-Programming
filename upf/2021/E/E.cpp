#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            bool b = ((i + j) & 1) && c != 'W';
            b |= ((i + j) % 2 == 0) && c != 'B';
            if (b) {
                cout << "invalide" << endl;
                return 0;
            }
        }
    }
    cout << "valide" << endl;
}