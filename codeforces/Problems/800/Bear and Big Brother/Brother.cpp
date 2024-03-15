#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, b;
    cin >> l >> b;
    int an = 0;
    while (l <= b)
        l *= 3, b *= 2, an++;

    cout << an << endl;
}