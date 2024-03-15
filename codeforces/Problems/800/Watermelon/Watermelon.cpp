#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    if (n & 1 || n < 4)
        cout << "NO\n";
    else
        cout << "YES\n";
}