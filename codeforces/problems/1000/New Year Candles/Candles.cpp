#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b; cin >> a >> b;

    int h = a;
    while (a >= b) {
        h += a / b;
        a = a % b + a / b;
    }

    cout << h << endl;
}