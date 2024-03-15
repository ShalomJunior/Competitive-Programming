#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 1e5;
    cout << n << " " << n - 1 << endl;
    for (int i = 1; i < n; i++) {
        cout << i << " " << i + 1 << endl;
    }

    for (int i = 0; i <= n; i++) {
        cout << 0 << " ";
    }
    cout << endl;
}