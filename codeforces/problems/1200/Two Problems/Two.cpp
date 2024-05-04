#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, t, a, b, da, db;
    cin >> x >> t >> a >> b >> da >> db;

    if (x == 0) {
        cout << "YES" << endl;
        return 0;
    }
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            if (a - i * da == x || b - j * db == x || a - i * da + b - j * db == x) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
}