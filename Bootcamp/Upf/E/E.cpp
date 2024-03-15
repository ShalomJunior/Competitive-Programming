#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            if ((i + j) & 1) {
                if (c != 'W') {
                    cout << "invalide" << endl;
                    return 0;
                }
            }

            if ((i + j) % 2 == 0) {
                if (c != 'B') {
                    cout << "invalide" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "valide" << endl;
}