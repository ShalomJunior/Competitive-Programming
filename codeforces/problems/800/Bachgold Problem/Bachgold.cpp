#include <bits/stdc++.h>

using namespace std;

void pf(int times) {
    for (int i = 0; i < times; i++)
        cout << "2 ";
}

int main() {
    int n; cin >> n;
    if (n & 1) {
        cout << (n - 3) / 2 + 1 << endl;
        pf((n - 3) / 2);
        cout << "3" << endl;
    }
    else {
        cout << n / 2 << endl;
        pf(n / 2);
    }
}