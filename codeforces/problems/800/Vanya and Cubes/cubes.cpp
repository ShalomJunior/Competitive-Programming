#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    int res = 0, comp = 0;
    while (res + comp * (comp + 1) / 2 <= n) {
        res += comp * (comp + 1) / 2;
        comp++;
    }
    cout << comp - 1 << endl;
}